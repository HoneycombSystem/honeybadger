#pragma once
#include "honeybadger/communication/protocols/protocols/interface/Protocol.hh"
#include "honeybadger/communication/server/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::protocols
{
class ApplicationProtocol : public interface::Protocol
{
  public:
    ApplicationProtocol(std::unique_ptr<server::interface::Server>);
    void run() override;
    void onMessage() override;

  private:
    std::unique_ptr<server::interface::Server> protocolServer_;
};
} // namespace honeybadger::communication::protocols