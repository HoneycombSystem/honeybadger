#pragma once

namespace honeybadger::communication::protocols::interface
{
class ApplicationProtocolService
{
  public:
    virtual ~ApplicationProtocolService() = default;
    virtual void start() = 0;
};
} // namespace honeybadger::communication::protocols::interface