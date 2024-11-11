#pragma once
#include "honeybadger/communication/network/socket/interface/ConnectedSocket.hh"

namespace honeybadger::communication::network
{
class SctpSocket;

class ConnectedSocket : public interface::ConnectedSocket
{
  public:
    ConnectedSocket(std::shared_ptr<SctpSocket>);
    ~ConnectedSocket() override;
    void close() override;
    bool isClosed() const override;
    common::coroutines::Task<void> send(const common::types::Payload &) override;
    common::coroutines::Task<common::types::Payload> receive() override;

  private:
    void closeSctpSocketAndResetPointer();
    std::shared_ptr<SctpSocket> sctpSocket_;
};
} // namespace honeybadger::communication::network