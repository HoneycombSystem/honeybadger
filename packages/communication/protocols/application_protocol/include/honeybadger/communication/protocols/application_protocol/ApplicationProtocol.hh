#pragma once
#include "honeybadger/communication/protocols/protocols/interface/Protocol.hh"
#include "honeybadger/communication/protocols/protocols/interface/ProtocolServer.hh"
#include <memory>

namespace honeybadger::communication::protocols
{
class ApplicationProtocol : public interface::Protocol
{
  public:
    ApplicationProtocol(std::unique_ptr<interface::ProtocolServer>);
    void run() override;
    void onMessage() override;

  private:
    std::unique_ptr<interface::ProtocolServer> protocolServer_;
};
} // namespace honeybadger::communication::protocols