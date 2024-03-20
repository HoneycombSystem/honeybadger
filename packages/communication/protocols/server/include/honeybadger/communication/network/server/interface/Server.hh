#pragma once

namespace honeybadger::communication::network::interface
{
class Server
{
  public:
    virtual ~Server() = default;
    virtual bool run() = 0;
    virtual bool stop() = 0;
};
} // namespace honeybadger::communication::network::interface