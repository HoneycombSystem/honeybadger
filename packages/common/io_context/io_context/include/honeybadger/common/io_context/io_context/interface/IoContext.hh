#pragma once
#include <functional>

namespace honeybadger::common::io_context::interface
{
class IOContext
{
  public:
    virtual ~IOContext() = default;
    virtual void run() = 0;
    virtual void stop() = 0;

    template<typename T>
    T* getNativeContext()
    {
        return dynamic_cast<T*>(getNativeContextImpl());
    }

  protected:
    virtual void* getNativeContextImpl() = 0;
};
} // namespace honeybadger::common::io_context::interface