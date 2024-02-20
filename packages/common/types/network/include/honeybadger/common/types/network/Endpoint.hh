#pragma once
// #include <arpa/inet.h>
// #include <netinet/in.h>
#include <stdexcept>
#include <string>

namespace honeybadger::common::types
{
struct Endpoint
{
    using ip_t = const char*;
    using port_t = unsigned short;

    const ip_t ip;
    const port_t port;
    enum class IpVersion
    {
        unknown,
        v4,
        v6
    } ipVersion;

    Endpoint(const ip_t& i, port_t p) : ip(i), port(p), ipVersion(IpVersion::unknown)
    {
        ipVersion = IpVersion::v4;
        // if(inet_pton(AF_INET, ip, nullptr))
        // {
        //     ipVersion = Endpoint::IpVersion::v4;
        // }
        // else if(inet_pton(AF_INET6, ip, nullptr))
        // {
        //     ipVersion = Endpoint::IpVersion::v6;
        // }
        // else
        // {
        //     throw std::runtime_error("Invalid IP address: " + std::string(ip));
        // }

        // if(port == 0)
        // {
        //     throw std::runtime_error("Invalid port: " + std::to_string(port));
        // }
    }
};
} // namespace honeybadger::common::types