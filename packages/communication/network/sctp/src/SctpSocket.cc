#include "honeybadger/communication/network/sctp/SctpSocket.hh"
#include "honeybadger/communication/network/socket/AddressFormatConverter.hh"
#include <memory>
#ifdef __linux__
    #include <arpa/inet.h>
    #include <linux/sctp.h>
    #include <netinet/in.h>
#elif _WIN32
    #error SCTP implementation for Windows is missing
#else
    #warning SCTP implementation for this system is missing
#endif
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/network/Logger.hh"
#include "honeybadger/communication/network/sctp/ConnectedSocket.hh"
#include <boost/asio.hpp>
#include <boost/asio/awaitable.hpp>
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/use_awaitable.hpp>
#include <boost/beast/core/flat_buffer.hpp>

namespace
{
template<typename ProtocolEndpoint>
ProtocolEndpoint buildAsioEndpoint(const honeybadger::common::types::Endpoint &endpoint)
{
    auto protocolEndpointBuilder = [](auto &sockaddrIn)
    {
        return ProtocolEndpoint{
            reinterpret_cast<sockaddr *>(&sockaddrIn),
            sizeof(sockaddrIn),
            IPPROTO_SCTP,
        };
    };
    switch(endpoint.ipVersion)
    {
        using namespace honeybadger::communication::network;
        using enum honeybadger::common::types::Endpoint::IpVersion;
        case v4:
        {
            auto sockaddrIn = convertEndpointToSockaddrIn(endpoint);
            return protocolEndpointBuilder(sockaddrIn);
        }
        case v6:
        {
            auto sockaddrIn6 = convertEndpointToSockaddrIn6(endpoint);
            return protocolEndpointBuilder(sockaddrIn6);
        }
        case unknown:
        default:
        {
            throw std::runtime_error("Unknown IP version");
        }
    }
}

void configure_sctp_socket(auto &socket)
{
    boost::asio::socket_base::keep_alive option(true);
    socket.set_option(option);

    // Struktura konfiguracji SCTP Heartbeat
    struct sctp_paddrparams heartbeat_params;
    std::memset(&heartbeat_params, 0, sizeof(heartbeat_params));

    // Pobranie aktualnych parametrów SCTP
    socklen_t opt_len = sizeof(heartbeat_params);
    if(getsockopt(socket.native_handle(), IPPROTO_SCTP, SCTP_PEER_ADDR_PARAMS, &heartbeat_params, &opt_len) < 0)
    {
        throw std::runtime_error("Failed to get SCTP_PEER_ADDR_PARAMS");
    }

    // Ustawienie interwału Heartbeat (np. 10 sekund)
    heartbeat_params.spp_hbinterval = 1000; // W milisekundach
    heartbeat_params.spp_flags |= SPP_HB_ENABLE; // Włącz Heartbeat
    heartbeat_params.spp_pathmaxrxt = 1; // Maksymalna liczba retransmisji

    // Zastosowanie parametrów SCTP
    if(setsockopt(socket.native_handle(),
                  IPPROTO_SCTP,
                  SCTP_PEER_ADDR_PARAMS,
                  &heartbeat_params,
                  sizeof(heartbeat_params)) < 0)
    {
        throw std::runtime_error("Failed to set SCTP_PEER_ADDR_PARAMS");
    }

    struct sctp_rtoinfo rtoinfo;
    std::memset(&rtoinfo, 0, sizeof(rtoinfo));
    rtoinfo.srto_max = 2000;
    if(setsockopt(socket.native_handle(), IPPROTO_SCTP, SCTP_RTOINFO, &rtoinfo, sizeof(rtoinfo)) < 0)
    {
        throw std::runtime_error("Failed to set SCTP_RTOINFO");
    }
    INFO_LOG("set heartbeat");

    struct sctp_event_subscribe events;
    std::memset(&events, 0, sizeof(events));
    events.sctp_association_event = 1;
    events.sctp_shutdown_event = 1;
    events.sctp_address_event = 1;
    events.sctp_send_failure_event = 1;
    events.sctp_peer_error_event = 1;
    events.sctp_partial_delivery_event = 1;
    events.sctp_adaptation_layer_event = 1;
    events.sctp_authentication_event = 1;
    events.sctp_sender_dry_event = 1;
    events.sctp_stream_reset_event = 1;
    setsockopt(socket.native_handle(), IPPROTO_SCTP, SCTP_EVENTS, &events, sizeof(events));
}

void handle_assoc_change(sctp_assoc_change *sac)
{
    switch(sac->sac_state)
    {
        case SCTP_COMM_UP:
            std::cout << "SCTP association established" << std::endl;
            break;
        case SCTP_COMM_LOST:
            std::cout << "SCTP association lost" << std::endl;
            break;
        case SCTP_RESTART:
            std::cout << "SCTP association restarted" << std::endl;
            break;
        case SCTP_SHUTDOWN_COMP:
            std::cout << "SCTP association shutdown complete" << std::endl;
            break;
        case SCTP_CANT_STR_ASSOC:
            std::cout << "SCTP association can't start" << std::endl;
            break;
        default:
            std::cout << "Unknown SCTP association change state: " << sac->sac_state << std::endl;
            break;
    }
}

void handle_peer_addr_change(sctp_paddr_change *spc)
{
    switch(spc->spc_state)
    {
        case SCTP_ADDR_AVAILABLE:
            std::cout << "SCTP peer address available" << std::endl;
            break;
        case SCTP_ADDR_UNREACHABLE:
            std::cout << "SCTP peer address unreachable" << std::endl;
            break;
        case SCTP_ADDR_REMOVED:
            std::cout << "SCTP peer address removed" << std::endl;
            break;
        case SCTP_ADDR_ADDED:
            std::cout << "SCTP peer address added" << std::endl;
            break;
        case SCTP_ADDR_MADE_PRIM:
            std::cout << "SCTP peer address made primary" << std::endl;
            break;
        case SCTP_ADDR_CONFIRMED:
            std::cout << "SCTP peer address confirmed" << std::endl;
            break;
        default:
            std::cout << "Unknown SCTP peer address change state: " << spc->spc_state << std::endl;
            break;
    }
}

void handle_read_notification(const boost::system::error_code &error, std::size_t ,
                              std::vector<unsigned char> &buffer)
{
    if(!error)
    {
        auto *sn = reinterpret_cast<sctp_notification *>(buffer.data());
        switch(sn->sn_header.sn_type)
        {
            case SCTP_ASSOC_CHANGE:
                handle_assoc_change(&sn->sn_assoc_change);
                break;
            case SCTP_PEER_ADDR_CHANGE:
                handle_peer_addr_change(&sn->sn_paddr_change);
                break;
            // Handle other notification types as needed
            default:
                std::cout << "Received unknown notification type: " << sn->sn_header.sn_type << std::endl;
                break;
        }

        // Continue reading notifications
    }
    else
    {
        std::cerr << "Notification read error: " << error.message() << std::endl;
    }
}
} // namespace

namespace honeybadger::communication::network
{

SctpSocket::~SctpSocket()
{
    closeConnectionOnBothSides();
}

SctpSocket::SctpSocket() :
    ioContext_(std::make_shared<boost::asio::io_context>()), acceptor_(*ioContext_),
    socket_(std::make_shared<Protocol::socket>(*ioContext_)), work_guard_(boost::asio::make_work_guard(*ioContext_))
{
    selectSctpProtocolForAcceptor();
}

bool SctpSocket::bind(const common::types::Endpoint &endpoint)
try
{
    DEBUG_LOG("SCTP socket bind to {}:{}", endpoint.ip, endpoint.port);
    const auto streamProtocolEndpoint = buildAsioEndpoint<Protocol::endpoint>(endpoint);
    acceptor_.bind(streamProtocolEndpoint);
    return true;
}
catch(const boost::system::system_error &error)
{
    WARN_LOG("SCTP socket bind to {}:{} failed: {}", endpoint.ip, endpoint.port, error.what());
    return false;
}
catch(const std::exception &error)
{
    WARN_LOG("SCTP socket bind to {}:{} failed: {}", endpoint.ip, endpoint.port, error.what());
    return false;
}
catch(...)
{
    WARN_LOG("SCTP socket bind to {}:{} failed: unknown error", endpoint.ip, endpoint.port);
    return false;
}

bool SctpSocket::listen()
try
{
    const auto maxListenConnections = Protocol::socket::max_listen_connections;
    DEBUG_LOG("SCTP socket listen with max connections: {}", maxListenConnections);
    acceptor_.listen(maxListenConnections);
    INFO_LOG("SCTP socket listen");
    return true;
}
catch(const boost::system::system_error &error)
{
    WARN_LOG("SCTP socket listen failed: {}", error.what());
    return false;
}
catch(const std::exception &error)
{
    WARN_LOG("SCTP socket listen failed: {}", error.what());
    return false;
}
catch(...)
{
    WARN_LOG("SCTP socket listen failed: unknown error");
    return false;
}

DISABLE_SWITCH_DEFAULT_WARNING_DUE_TO_BOOST_COROUTINES

common::coroutines::Task<std::unique_ptr<interface::ConnectedSocket>> SctpSocket::accept()
try
{
    INFO_LOG("SCTP socket accept");
    auto clientSocket = co_await acceptor_.async_accept(boost::asio::use_awaitable);
    boost::asio::socket_base::keep_alive option(true);
    clientSocket.set_option(option);

    configure_sctp_socket(clientSocket);
    std::unique_ptr<interface::ConnectedSocket> connectedSocket = std::make_unique<ConnectedSocket>(
        createConnectedSocketFromThis(std::make_shared<Protocol::socket>(std::move(clientSocket))));
    co_return std::move(connectedSocket);
}
catch(const boost::system::system_error &error)
{
    WARN_LOG("SCTP socket accept failed: {}", error.what());
    co_return nullptr;
}
catch(const std::exception &error)
{
    WARN_LOG("SCTP socket accept failed: {}", error.what());
    co_return nullptr;
}
catch(...)
{
    WARN_LOG("SCTP socket accept failed: unknown error");
    co_return nullptr;
}

void SctpSocket::startloop()
{
    boost::asio::co_spawn(*ioContext_, acceptloop(), boost::asio::detached);
    ioContext_->run();
    INFO_LOG("io context run");
}

common::coroutines::Task<void> SctpSocket::acceptloop()
{
    std::vector<std::shared_ptr<interface::ConnectedSocket>> connectedSockets;
    while(true)
    {
        std::shared_ptr<interface::ConnectedSocket> connectedSocket = co_await accept();
        INFO_LOG("SCTP accepted");
        connectedSockets.push_back(connectedSocket);
        co_await boost::asio::post(ioContext_->get_executor(), boost::asio::use_awaitable);
        boost::asio::co_spawn(ioContext_->get_executor(), connectedSocket->run(), boost::asio::detached);
        INFO_LOG("connected socket run");
    }
}
common::coroutines::Task<void> SctpSocket::send(const common::types::Payload &payload)
{
    co_await boost::asio::async_write(*socket_,boost::asio::buffer(payload.value().data(), payload.value().size()),
                             boost::asio::use_awaitable);
    co_return;
}

common::coroutines::Task<common::types::Payload> SctpSocket::receive()
{
    while(true)
    {
        co_await socket_->async_wait(Protocol::socket::wait_read, boost::asio::use_awaitable);
        std::vector<std::uint8_t> buffer_(socket_->available());
        try
        {
        auto [ec, readed] = co_await boost::asio::async_read(*socket_, boost::asio::buffer(buffer_), boost::asio::as_tuple(boost::asio::use_awaitable));
        if(ec)
        {
            WARN_LOG("SCTP receive : {}:{}", ec.value(), ec.message());
            throw std::runtime_error(ec.message());
            co_return common::types::Payload();
        }
        if(buffer_.size()!=0)
        handle_read_notification(ec, readed, buffer_);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }


        co_return common::types::Payload(buffer_);
    }
}

RESTORE_WARNINGS

void SctpSocket::close()
{
    closeConnectionOnBothSides();
}

bool SctpSocket::isClosed() const
{
    return socket_ == nullptr or not socket_->is_open();
}

void SctpSocket::selectSctpProtocolForAcceptor()
{
    acceptor_.open({AF_INET, IPPROTO_SCTP});
}

bool SctpSocket::closeConnectionOnBothSides()
{
    try
    {
        socket_->shutdown(Protocol::socket::shutdown_both);
        acceptor_.close();
        socket_.reset();
        INFO_LOG("SCTP closed");
    }
    catch(const boost::system::system_error &error)
    {
        WARN_LOG("SCTP close failed: {}", error.what());
        return false;
    }
    catch(const std::exception &error)
    {
        WARN_LOG("SCTP close failed: {}", error.what());
        return false;
    }
    catch(...)
    {
        WARN_LOG("SCTP close failed: unknown error");
        return false;
    }
    return true;
}

std::shared_ptr<SctpSocket> SctpSocket::createConnectedSocketFromThis(std::shared_ptr<Protocol::socket> socket)
{
    auto connectedSocket = std::make_shared<SctpSocket>();
    connectedSocket->socket_ = std::move(socket);
    return connectedSocket;
}
} // namespace honeybadger::communication::network
