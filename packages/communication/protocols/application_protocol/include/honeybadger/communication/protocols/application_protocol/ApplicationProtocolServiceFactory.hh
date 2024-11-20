#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/protocols/protocols/interface/ProtocolServiceFactory.hh"

namespace honeybadger::communication::protocols
{
class ApplicationProtocolServiceFactory : public interface::ProtocolServiceFactory
{
  public:
    ApplicationProtocolServiceFactory(const honeybadger::common::types::Endpoint &);
    std::unique_ptr<interface::ProtocolService> create() override;

  private:
    honeybadger::common::types::Endpoint endpoint_;
};
} // namespace honeybadger::communication::protocols