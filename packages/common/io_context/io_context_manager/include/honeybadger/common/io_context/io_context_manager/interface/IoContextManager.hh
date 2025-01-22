#pragma once
#include <memory>

namespace honeybadger::common::io_context::interface
{
class IOContext;

class IOContextManager
{
  public:
    virtual ~IOContextManager() = default;

    virtual std::shared_ptr<IOContext> getIOContext() = 0;
};
} // namespace honeybadger::common::io_context::interface