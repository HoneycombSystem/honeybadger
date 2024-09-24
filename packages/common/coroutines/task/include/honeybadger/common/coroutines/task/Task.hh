#pragma once
#include <coroutine>

namespace honeybadger::common::coroutines
{
template<typename T>
class Task
{
};
class Task<int>;
} // namespace honeybadger::common::coroutines