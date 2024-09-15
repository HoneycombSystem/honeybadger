#pragma once
#include <boost/asio/awaitable.hpp>

namespace honeybadger::common::coroutines
  {
    template<typename T>
class Task
{
public:
    using AwaitableType = boost::asio::awaitable<T>;

    Task(AwaitableType awaitable) : awaitable_(std::move(awaitable)) {}

    AwaitableType get_awaitable() { return std::move(awaitable_); }

private:
    AwaitableType awaitable_;
};
  }