#pragma once
#ifdef __linux__
    #include <arpa/inet.h>
    #include <netinet/in.h>
#elif _WIN32
    #error Implementation for Windows is missing
#else
    #error Implementation for this system is missing
#endif

namespace honeybadger::common::types
{
struct Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network
{
sockaddr_in convertEndpointToSockaddrIn(const common::types::Endpoint &);
sockaddr_in6 convertEndpointToSockaddrIn6(const common::types::Endpoint &);
} // namespace honeybadger::communication::network