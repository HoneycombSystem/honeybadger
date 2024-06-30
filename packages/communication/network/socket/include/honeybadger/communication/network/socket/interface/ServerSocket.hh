#pragma once

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network::interface
{
struct ServerSocket
{
    virtual ~ServerSocket() = default;
    virtual bool bind(const common::types::Endpoint &) = 0;
    virtual bool listen() = 0;
    virtual bool accept() = 0;
};
} // namespace honeybadger::communication::network::interface