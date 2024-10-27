#pragma once
#include "honeybadger/communication/network/socket/interface/ConnectedSocket.hh"
#include "honeybadger/communication/network/socket/interface/ServerSocket.hh"
#include <honeybadger/common/coroutines/task/Task.hh>

namespace honeybadger::communication::network
{
class SctpServerSocket : public interface::ServerSocket
{
  public:
    SctpServerSocket(const common::types::Endpoint &);
    ~SctpServerSocket();
    bool bind(const common::types::Endpoint &) override;
    bool listen() override;
    common::coroutines::Task<std::unique_ptr<interface::ConnectedSocket>> accept() override;
    void close() override;
    bool isClosed() const override;
};
} // namespace honeybadger::communication::network