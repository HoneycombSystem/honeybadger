#pragma once
#ifdef __linux__
#include <netinet/in.h>
#include <arpa/inet.h>
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
    struct AddressFormatConverter
    {
        sockaddr_in convertEndpointToSockaddrIn(const common::types::Endpoint &) const;
        sockaddr_in6 convertEndpointToSockaddrIn6(const common::types::Endpoint &) const;
};
}