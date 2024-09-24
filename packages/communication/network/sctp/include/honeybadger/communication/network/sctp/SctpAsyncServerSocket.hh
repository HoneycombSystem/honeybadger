#pragma once
#include "honeybadger/communication/network/socket/interface/AsyncServerSocket.hh"

namespace honeybadger::communication::network
{
class SctpAsyncServerSocket : public interface::AsyncServerSocket
{
  public:
    SctpAsyncServerSocket(const common::types::Endpoint &);
    ~SctpAsyncServerSocket();
    bool bind(const common::types::Endpoint &) override;
    bool listen() override;
    common::coroutines::Task<interface::CloseableSocket> accept() override;
};
} // namespace honeybadger::communication::network