#pragma once
#include "honeybadger/communication/protocols/protocols/interface/ProtocolServer.hh"
#include <honeybadger/communication/server/server/interface/Server.hh>
#include <memory>

namespace honeybadger::communication::protocols
{
class ApplicationProtocolServer : public interface::ProtocolServer
{
  public:
    ApplicationProtocolServer(std::unique_ptr<server::interface::Server>);
    void run() override;

  private:
    std::unique_ptr<server::interface::Server> server_;
};
} // namespace honeybadger::communication::protocols