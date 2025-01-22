#pragma once
#include "honeybadger/common/io_context/io_context_manager/interface/IOContextManager.hh"
#include <memory>

namespace honeybadger::common::io_context
{
class IOContextManager
{
  public:
    virtual ~IOContextManager() = default;
    std::shared_ptr<interface::IOContext> getIOContext();

  private:
    std::shared_ptr<interface::IOContext> ioContext_{nullptr};
};
} // namespace honeybadger::common::io_context