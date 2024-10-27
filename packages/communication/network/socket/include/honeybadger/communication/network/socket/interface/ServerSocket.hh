#pragma once
#include "honeybadger/common/coroutines/task/Task.hh"
#include "honeybadger/communication/network/socket/interface/CloseableSocket.hh"
#include "honeybadger/communication/network/socket/interface/ConnectedSocket.hh"
#include <memory>

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network::interface
{
struct ServerSocket : public CloseableSocket
{
    virtual ~ServerSocket() = default;
    virtual bool bind(const common::types::Endpoint &) = 0;
    virtual bool listen() = 0;
    virtual common::coroutines::Task<std::unique_ptr<interface::ConnectedSocket>> accept() = 0;
};
} // namespace honeybadger::communication::network::interface