#include "honeybadger/communication/network/socket/AddressFormatConverter.hh"
#include "honeybadger/common/types/network/Endpoint.hh"

namespace honeybadger::communication::network
{
    sockaddr_in AddressFormatConverter::convertEndpointToSockaddrIn(const common::types::Endpoint &endpoint) const
    {
        sockaddr_in sockaddrIn;
        sockaddrIn.sin_family = AF_INET;
        sockaddrIn.sin_addr.s_addr = inet_addr(endpoint.ip);
        sockaddrIn.sin_port = htons(endpoint.port);
        return sockaddrIn;
    }

    sockaddr_in6 AddressFormatConverter::convertEndpointToSockaddrIn6(const common::types::Endpoint &endpoint) const
    {
        sockaddr_in6 sockaddrIn6;
        sockaddrIn6.sin6_family = AF_INET6;
        inet_pton(AF_INET6, endpoint.ip, &sockaddrIn6.sin6_addr);
        sockaddrIn6.sin6_port = htons(endpoint.port);
        return sockaddrIn6;
    }
} // namespace honeybadger::communication::network