#pragma once

namespace honeybadger::communication::protocols::interface
{
class ApplicationProtocol
{
  public:
    virtual ~ApplicationProtocol() = default;
    virtual void start() = 0;
    virtual void onMessage() = 0;
};
} // namespace honeybadger::communication::protocols::interface