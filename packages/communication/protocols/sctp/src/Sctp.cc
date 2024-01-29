#include "honeybadger/communication/protocols/sctp/Sctp.hh"
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/common/types/network/Payload.hh"
#include "honeybadger/communication/protocols/Logger.hh"
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
    switch(endpoint.ipVersion)
    {
        case honeybadger::common::types::Endpoint::IpVersion::v4:
        {
            auto sockaddrIn = prepareSockaddrIn(endpoint);
            return ProtocolEndpoint{
                reinterpret_cast<sockaddr *>(&sockaddrIn),
                sizeof(sockaddrIn),
                IPPROTO_SCTP,
            };
        }
        case honeybadger::common::types::Endpoint::IpVersion::v6:
        {
            auto sockaddrIn6 = prepareSockaddrIn6(endpoint);
            return ProtocolEndpoint{
                reinterpret_cast<sockaddr *>(&sockaddrIn6),
                sizeof(sockaddrIn6),
                IPPROTO_SCTP,
            };
        }
        case honeybadger::common::types::Endpoint::IpVersion::unknown:
        default:
            throw std::runtime_error("Unknown IP version");
    }
}
} // namespace

namespace honeybadger::communication::protocols
{
Sctp::Sctp() : ioContext_(), acceptor_(ioContext_), socket_(ioContext_)
{
    acceptor_.open({AF_INET, IPPROTO_SCTP});
}

bool Sctp::bind(const common::types::Endpoint &endpoint)
{
    try
    {
        const auto streamProtocolEndpoint = buildAsioEndpoint<Protocol::endpoint>(endpoint);
        acceptor_.bind(streamProtocolEndpoint);
    }
    catch(const boost::system::system_error &error)
    {
        WARN_LOG("SCTP socket bind to {}:{} failed: {}", endpoint.ip, endpoint.port, error.what());
        throw;
        return false;
    }
    catch(const std::exception &error)
    {
        WARN_LOG("SCTP socket bind to {}:{} failed: {}", endpoint.ip, endpoint.port, error.what());
        throw;
        return false;
    }
    catch(...)
    {
        WARN_LOG("SCTP socket bind to {}:{} failed: unknown error", endpoint.ip, endpoint.port);
        throw;
        return false;
    }
    return true;
}

bool Sctp::listen()
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
        throw;
        return false;
    }
    catch(const std::exception &error)
    {
        WARN_LOG("SCTP socket listen failed: {}", error.what());
        throw;
        return false;
    }
    catch(...)
    {
        WARN_LOG("SCTP socket listen failed: unknown error");
        throw;
        return false;
    }
    return true;
}

bool Sctp::accept()
{
    try
    {
        acceptor_.accept(socket_);
        INFO_LOG("SCTP socket accepted");
    }
    catch(const boost::system::system_error &error)
    {
        WARN_LOG("SCTP socket accept failed: {}", error.what());
        throw;
        return false;
    }
    catch(const std::exception &error)
    {
        WARN_LOG("SCTP socket accept failed: {}", error.what());
        throw;
        return false;
    }
    catch(...)
    {
        WARN_LOG("SCTP socket accept failed: unknown error");
        throw;
        return false;
    }
    return true;
}

bool Sctp::close()
{
    try
    {
        socket_.close();
        INFO_LOG("SCTP socket closed");
    }
    catch(const boost::system::system_error &error)
    {
        WARN_LOG("SCTP socket close failed: {}", error.what());
        throw;
        return false;
    }
    catch(const std::exception &error)
    {
        WARN_LOG("SCTP socket close failed: {}", error.what());
        throw;
        return false;
    }
    catch(...)
    {
        WARN_LOG("SCTP socket close failed: unknown error");
        throw;
        return false;
    }
    return true;
}
} // namespace honeybadger::communication::protocols