#include "honeybadger/communication/network/sctp/SctpAsyncSocket.hh"
#include <memory>
#ifdef __linux__
    #include <arpa/inet.h>
    #include <linux/sctp.h>
    #include <netinet/in.h>
#elif _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #warning SCTP implementation for Windows is missing
#else
    #error SCTP implementation for this system is missing
#endif
#include <boost/asio.hpp>
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/network/Logger.hh"

namespace
{
sockaddr_in prepareSockaddrIn(const honeybadger::common::types::Endpoint &endpoint)
{
    sockaddr_in sockaddrIn;
    sockaddrIn.sin_family = AF_INET;
    sockaddrIn.sin_addr.s_addr = inet_addr(endpoint.ip);
    sockaddrIn.sin_port = htons(endpoint.port);
    return sockaddrIn;
}

sockaddr_in6 prepareSockaddrIn6(const honeybadger::common::types::Endpoint &endpoint)
{
    sockaddr_in6 sockaddrIn6;
    sockaddrIn6.sin6_family = AF_INET6;
    sockaddrIn6.sin6_port = htons(endpoint.port);
    inet_pton(AF_INET6, endpoint.ip, &sockaddrIn6.sin6_addr);
    return sockaddrIn6;
}

template<typename ProtocolEndpoint>
ProtocolEndpoint buildAsioEndpoint(const honeybadger::common::types::Endpoint &endpoint)
{
    auto protocolEndpointBuilder = [](auto &sockaddrIn) {
        return ProtocolEndpoint{
            reinterpret_cast<sockaddr *>(&sockaddrIn),
            sizeof(sockaddrIn),
            IPPROTO_SCTP,
        };
    };
    switch(endpoint.ipVersion)
    {
        case honeybadger::common::types::Endpoint::IpVersion::v4:
        {
            auto sockaddrIn = prepareSockaddrIn(endpoint);
            return protocolEndpointBuilder(sockaddrIn);
        }
        case honeybadger::common::types::Endpoint::IpVersion::v6:
        {
            auto sockaddrIn6 = prepareSockaddrIn6(endpoint);
            return protocolEndpointBuilder(sockaddrIn6);
        }
        case honeybadger::common::types::Endpoint::IpVersion::unknown:
        default:
            throw std::runtime_error("Unknown IP version");
    }
}
} // namespace

namespace honeybadger::communication::network
{
SctpAsyncSocket::SctpAsyncSocket() : ioContext_(), acceptor_(ioContext_), socket_(ioContext_)
{
    acceptor_.open({AF_INET, IPPROTO_SCTP});
}

bool SctpAsyncSocket::bind(const common::types::Endpoint &endpoint)
{
    try
    {
        DEBUG_LOG("SCTP socket bind to {}:{}", endpoint.ip, endpoint.port);
        const auto streamProtocolEndpoint = buildAsioEndpoint<Protocol::endpoint>(endpoint);
        acceptor_.bind(streamProtocolEndpoint);
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
    return true;
}

bool SctpAsyncSocket::listen()
{
    const auto maxListenConnections = Protocol::socket::max_listen_connections;
    DEBUG_LOG("SCTP socket listen with max connections: {}", maxListenConnections);
    try
    {
        acceptor_.listen(maxListenConnections);
        INFO_LOG("SCTP socket listen");
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
    return true;
}

bool SctpAsyncSocket::accept()
{
    try
    {
        // acceptor_.async_accept();
        INFO_LOG("SCTP socket accepted new connection");
        return true;
    }
    catch(const boost::system::system_error &error)
    {
        WARN_LOG("SCTP socket accept failed: {}", error.what());
        return false;
    }
    catch(const std::exception &error)
    {
        WARN_LOG("SCTP socket accept failed: {}", error.what());
        return false;
    }
    catch(...)
    {
        WARN_LOG("SCTP socket accept failed: unknown error");
        return false;
    }
}

// void Sctp::acceptHandler(boost::system::error_code ec, Protocol::socket)
// {
//     if(ec)
//     {
//         WARN_LOG("SCTP socket accept failed: {}", ec.message());
//         return;
//     }

//     INFO_LOG("SCTP socket accepted new connection");
//     // auto session = std::make_shared<Client>(std::move(socket));
//     // session->run();
//     // clients_.emplace_back(std::move(session));
//     acceptHandler();
// }

// void Sctp::acceptHandler()
// {
//     acceptor_.async_accept(socket_,
//                            [this](boost::system::error_code ec)
//     {
//         acceptHandler(ec, std::move(socket_));
//     });
// }

bool SctpAsyncSocket::close()
{
    try
    {
        acceptor_.close();
        socket_.close();
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
} // namespace honeybadger::communication::network