#pragma once
#include "honeybadger/common/coroutines/task/Task.hh"

namespace honeybadger::common::io_context::interface
{
class AsioTask
{
  public:
    virtual ~AsioTask() = default;
    virtual void spawnTask(std::function<common::coroutines::Task<void>()>) = 0;
};
} // namespace honeybadger::common::io_context::interface