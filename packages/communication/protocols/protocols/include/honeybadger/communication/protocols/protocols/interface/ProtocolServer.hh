#pragma once

namespace honeybadger::communication::protocols::interface
{
class ProtocolServer
{
  public:
    virtual ~ProtocolServer() = default;
    virtual void run() = 0;
};
} // namespace honeybadger::communication::protocols::interface