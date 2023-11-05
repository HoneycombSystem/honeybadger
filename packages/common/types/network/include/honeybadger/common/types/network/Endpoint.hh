#pragma once

namespace honeybadger::common::types
{
struct Endpoint
{
    using Ip = const char*;
    using Port = unsigned short;
    const Ip ip;
    const Port port;

    Endpoint(const Ip& i, Port p) : ip(i), port(p)
    {
    }
};
} // namespace honeybadger::common::types