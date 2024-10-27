#pragma once

namespace honeybadger::communication::protocols::interface
{
class ProtocolService
{
  public:
    virtual ~ProtocolService() = default;
    virtual void start() = 0;
};
} // namespace honeybadger::communication::protocols::interface