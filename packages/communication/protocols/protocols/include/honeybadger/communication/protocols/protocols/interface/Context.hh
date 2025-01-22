#pragma once
#include <memory>

namespace honeybadger::common::io_context::interface
{
class IOContextManager;
} // namespace honeybadger::common::io_context::interface

namespace honeybadger::communication::protocols::interface
{
class Context
{
  public:
    virtual ~Context() = default;
    virtual std::shared_ptr<common::io_context::interface::IOContextManager> getIOContextManager() = 0;
};
} // namespace honeybadger::communication::protocols::interface