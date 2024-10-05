#pragma once
#include "honeybadger/communication/protocols/application_protocol/interface/ApplicationProtocolServiceFactory.hh"

namespace honeybadger::communication::protocols
{
class ApplicationProtocolServiceFactory : public interface::ApplicationProtocolServiceFactory
{
  public:
    ApplicationProtocolServiceFactory();
    std::unique_ptr<interface::ApplicationProtocolService> create() override;
};
} // namespace honeybadger::communication::protocols