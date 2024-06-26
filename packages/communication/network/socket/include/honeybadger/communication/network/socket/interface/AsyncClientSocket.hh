#pragma once

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network::interface
{
struct AsyncClientSocket
{
    virtual ~AsyncClientSocket() = default;
    virtual bool connect(const common::types::Endpoint &) = 0;
};
} // namespace honeybadger::communication::network::interface