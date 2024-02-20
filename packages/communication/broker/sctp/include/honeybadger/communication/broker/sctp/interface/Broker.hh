#pragma once

namespace honeybadger::communication::broker::interface
{
class Broker
{
  public:
    virtual ~Broker() = default;
    virtual void start() = 0;
    virtual void stop() = 0;
};
} // namespace honeybadger::communication::broker::interface