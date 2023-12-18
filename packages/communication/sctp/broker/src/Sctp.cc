#include "honeybadger/communication/sctp/broker/Sctp.hh"
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/common/types/network/Payload.hh"
#include "honeybadger/communication/sctp/Logger.hh"
#include <memory>
#ifdef __linux__
    #include <arpa/inet.h>
    #include <linux/sctp.h>
    #include <netinet/in.h>
#elif _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #warning Code for SCTP implementation for this Windows is missing
#else
    #error Code for SCTP implementation for this system is missing
#endif

namespace honeybadger::communication::sctp
{
Sctp::Sctp() : ioContext_(), acceptor_(ioContext_), socket_(ioContext_)
{
    acceptor_.open({AF_INET, IPPROTO_SCTP});
}

bool Sctp::bind(const common::types::Endpoint &endpoint)
{
    sockaddr_in sockaddrIn;
    sockaddrIn.sin_family = AF_INET;
    sockaddrIn.sin_addr.s_addr = inet_addr(endpoint.ip);
    sockaddrIn.sin_port = htons(endpoint.port);
    const auto streamProtocolEndpoint = Protocol::endpoint{
        reinterpret_cast<sockaddr *>(&sockaddrIn),
        sizeof(sockaddrIn),
        IPPROTO_SCTP,
    };
    try
    {
        acceptor_.bind(streamProtocolEndpoint);
        INFO_LOG("SCTP socket bind to {}:{}", endpoint.ip, endpoint.port);
    }
    catch(const boost::system::system_error &error)
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

bool Sctp::listen()
{
    const auto maxListenConnections = Protocol::socket::max_listen_connections;
    DEBUG_LOG("SCTP socket listen with max connections: {}", maxListenConnections);
    try
    {
        acceptor_.listen(maxListenConnections);
    }
    catch(const boost::system::system_error &error)
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

void Sctp::acceptHandler(boost::system::error_code ec, Protocol::socket socket)
{
    if(ec)
    {
        WARN_LOG("SCTP socket accept failed: {}", ec.message());
        return;
    }

    INFO_LOG("SCTP socket accepted new connection");
    auto session = std::make_shared<Client>(std::move(socket));
    session->start();
    clients_.emplace_back(std::move(session));
    acceptHandler();
}

void Sctp::acceptHandler()
{
    acceptor_.async_accept(socket_,
                           [this](boost::system::error_code ec)
                           {
        acceptHandler(ec, std::move(socket_));
    });
}

bool Sctp::accept()
{
    try
    {
        acceptHandler();
        if(not runned)
        {
            INFO_LOG("SCTP socket run");
            ioContext_.run();
            runned = true;
        }
    }
    catch(const boost::system::system_error &error)
    {
        WARN_LOG("SCTP socket accept failed: {}", error.what());
        return false;
    }
    catch(...)
    {
        WARN_LOG("SCTP socket accept failed: unknown error");
        return false;
    }
    return true;
}

bool Sctp::close()
{
    acceptor_.close();
    return true;
}
} // namespace honeybadger::communication::sctp