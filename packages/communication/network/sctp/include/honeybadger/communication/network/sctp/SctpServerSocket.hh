#pragma once
#include "honeybadger/communication/network/socket/interface/ConnectedSocket.hh"
#include "honeybadger/communication/network/socket/interface/ServerSocket.hh"
#include <honeybadger/common/coroutines/task/Task.hh>
#include <honeybadger/common/types/network/Endpoint.hh>

namespace honeybadger::communication::network
{
class SctpSocket;

class SctpServerSocket : public interface::ServerSocket
{
  public:
    SctpServerSocket();
    ~SctpServerSocket();
    bool bind(const common::types::Endpoint &) override;
    bool listen() override;
    common::coroutines::Task<std::unique_ptr<interface::ConnectedSocket>> accept() override;
    void close() override;
    bool isClosed() const override;

  private:
    void closeSctpSocketAndResetPointer();
    std::unique_ptr<SctpSocket> sctpSocket_;
};
} // namespace honeybadger::communication::network