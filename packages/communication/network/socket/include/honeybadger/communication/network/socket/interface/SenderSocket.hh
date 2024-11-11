#pragma once
#include "honeybadger/common/coroutines/task/Task.hh"
#include "honeybadger/common/types/network/Payload.hh"

namespace honeybadger::communication::network::interface
{
struct SenderSocket
{
    virtual ~SenderSocket() = default;
    virtual common::coroutines::Task<void> send(const common::types::Payload &) = 0;
};
} // namespace honeybadger::communication::network::interface