#pragma once
#include <boost/asio/awaitable.hpp>
#include <coroutine>

namespace honeybadger::common::coroutines
{
template<typename T>
using Task = boost::asio::awaitable<T>;
} // namespace honeybadger::common::coroutines