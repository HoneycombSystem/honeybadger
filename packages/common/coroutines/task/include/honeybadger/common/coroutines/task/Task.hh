#pragma once
#include <boost/asio/awaitable.hpp>
#include <boost/asio/experimental/use_coro.hpp>
#include <coroutine>

namespace honeybadger::common::coroutines
{
template<typename T>
using Task = boost::asio::awaitable<T>;

} // namespace honeybadger::common::coroutines

#ifdef __GNUC__
    #define DO_PRAGMA(x) _Pragma(#x)

    #define DISABLE_SWITCH_DEFAULT_WARNING_DUE_TO_BOOST_COROUTINES \
        DO_PRAGMA(GCC diagnostic push)                             \
        DO_PRAGMA(GCC diagnostic ignored "-Wswitch-default")

    #define RESTORE_WARNINGS DO_PRAGMA(GCC diagnostic pop)
#else
    #define DISABLE_SWITCH_DEFAULT_WARNING
    #define RESTORE_WARNINGS
#endif
