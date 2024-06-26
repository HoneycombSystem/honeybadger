#pragma once

namespace honeybadger::communication::network::interface
{
struct AsyncReceiverSocket
{
    virtual ~AsyncReceiverSocket() = default;
    virtual void receive() = 0;
};
} // namespace honeybadger::communication::network::interface