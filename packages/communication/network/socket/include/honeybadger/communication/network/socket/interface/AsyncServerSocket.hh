#pragma once
#include "honeybadger/common/coroutines/task/Task.hh"
#include "honeybadger/communication/network/socket/interface/CloseableSocket.hh"

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network::interface
{
struct AsyncServerSocket
{
    virtual ~AsyncServerSocket() = default;
    virtual bool bind(const common::types::Endpoint &) = 0;
    virtual bool listen() = 0;
    virtual common::coroutines::Task<CloseableSocket> accept() = 0;
};
} // namespace honeybadger::communication::network::interface