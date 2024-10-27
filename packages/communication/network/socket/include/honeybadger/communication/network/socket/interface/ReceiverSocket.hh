#pragma once

namespace honeybadger::common::types
{
class Payload;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network::interface
{
struct ReceiverSocket
{
    virtual ~ReceiverSocket() = default;
    virtual common::types::Payload receive() = 0;
};
} // namespace honeybadger::communication::network::interface