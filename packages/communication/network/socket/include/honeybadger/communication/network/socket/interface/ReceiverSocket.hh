#pragma once
#include "honeybadger/common/coroutines/task/Task.hh"
#include "honeybadger/common/types/network/Payload.hh"

namespace honeybadger::communication::network::interface
{
struct ReceiverSocket
{
    virtual ~ReceiverSocket() = default;
    virtual common::coroutines::Task<common::types::Payload> receive() = 0;
};
} // namespace honeybadger::communication::network::interface