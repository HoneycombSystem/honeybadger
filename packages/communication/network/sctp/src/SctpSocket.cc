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
#include <boost/asio/experimental/coro.hpp>

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
} // namespace

namespace honeybadger::communication::network
{
SctpSocket::~SctpSocket()
{
    closeConnectionOnBothSides();
}

SctpSocket::SctpSocket() :
    ioContext_(std::make_shared<boost::asio::io_context>()), acceptor_(*ioContext_),
    socket_(std::make_shared<Protocol::socket>(*ioContext_))
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
    ioContext_->run();
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
    auto clientSocket = co_await acceptor_.async_accept(boost::asio::use_awaitable);
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

RESTORE_WARNINGS

void SctpSocket::close()
{
    closeConnectionOnBothSides();
}

bool SctpSocket::isClosed() const
{
    return socket_->is_open();
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
