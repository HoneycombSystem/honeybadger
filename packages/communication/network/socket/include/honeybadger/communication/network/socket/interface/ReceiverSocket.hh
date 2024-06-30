#pragma once

namespace honeybadger::communication::network::interface
{
struct ReceiverSocket
{
    virtual ~ReceiverSocket() = default;
    virtual void receive() = 0;
};
} // namespace honeybadger::communication::network::interface