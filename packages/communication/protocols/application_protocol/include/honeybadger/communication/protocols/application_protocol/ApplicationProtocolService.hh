#pragma once
#include "honeybadger/communication/protocols/protocols/interface/Protocol.hh"
#include "honeybadger/communication/protocols/protocols/interface/ProtocolService.hh"
#include <memory>

namespace honeybadger::communication::protocols
{
class ApplicationProtocolService : public interface::ProtocolService
{
  private:
    std::unique_ptr<interface::Protocol> applicationProtocol_;

  public:
    ApplicationProtocolService(std::unique_ptr<interface::Protocol>);
    void start() override;
};
} // namespace honeybadger::communication::protocols