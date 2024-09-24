#pragma once
#include "honeybadger/communication/network/socket/interface/AsyncServerSocket.hh"
#include "honeybadger/communication/server/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::server
{
class ApplicationProtocolServer : public interface::Server
{
  private:
    std::unique_ptr<network::interface::AsyncServerSocket> asyncServerSocket_;

  public:
    ApplicationProtocolServer(std::unique_ptr<network::interface::AsyncServerSocket>);
    ~ApplicationProtocolServer();
    void start() override;
    void stop() override;
};
} // namespace honeybadger::communication::server