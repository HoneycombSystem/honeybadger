#pragma once

namespace honeybadger::common::types
{
class Uuid;
} // namespace honeybadger::common::types

namespace honeybadger::communication::server::interface
{
class Client
{
  public:
    virtual ~Client() = default;
    virtual void run() = 0;
    virtual bool isRunning() const = 0;
    virtual common::types::Uuid getId() const = 0;
};
} // namespace honeybadger::communication::server::interface