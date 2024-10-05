#pragma once
#include "honeybadger/communication/protocols/application_protocol/interface/ApplicationProtocolService.hh"

namespace honeybadger::communication::protocols
{
class ApplicationProtocolService : public interface::ApplicationProtocolService
{
  public:
    ApplicationProtocolService();
    void start() override;
};
} // namespace honeybadger::communication::protocols