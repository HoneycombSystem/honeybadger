#pragma once

namespace honeybadger::communication::sctp::interface
{
class Broker
{
  public:
    virtual ~Broker() = default;
    virtual void start() = 0;
    virtual void stop() = 0;
};
} // namespace honeybadger::communication::sctp::interface