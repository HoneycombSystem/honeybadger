#pragma once
namespace honeybadger::communication::network::interface
{
class Server
{
  public:
    virtual ~Server() = default;
    virtual void run() = 0;
    virtual void stop() = 0;
}
} // namespace honeybadger::communication::network::interface