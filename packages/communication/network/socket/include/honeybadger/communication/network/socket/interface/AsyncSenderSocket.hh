#pragma once

namespace honeybadger::common::types
{
class Payload;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network::interface
{
struct AsyncSenderSocket
{
    virtual ~AsyncSenderSocket() = default;
    virtual void send(const common::types::Payload &) = 0;
};
} // namespace honeybadger::communication::network::interface