#pragma once

namespace honeybadger::communication::network::interface
{
struct CloseableSocket
{
    virtual ~CloseableSocket() = default;
    virtual void close() = 0;
    virtual bool isClosed() const = 0;
};
} // namespace honeybadger::communication::network::interface