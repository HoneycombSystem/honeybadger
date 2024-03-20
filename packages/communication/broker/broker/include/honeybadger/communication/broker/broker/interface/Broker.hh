#pragma once

namespace honeybadger::communication::broker::interface
{
class Broker
{
  public:
    virtual ~Broker() = default;
    virtual void run() = 0;
};
} // namespace honeybadger::communication::broker::interface