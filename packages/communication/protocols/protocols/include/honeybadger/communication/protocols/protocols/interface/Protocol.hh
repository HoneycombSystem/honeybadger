#pragma once

namespace honeybadger::communication::protocols::interface
{
class Protocol
{
  public:
    virtual ~Protocol() = default;
    virtual void run() = 0;
    virtual void onMessage() = 0;
};
} // namespace honeybadger::communication::protocols::interface