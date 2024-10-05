#pragma once
#include "honeybadger/communication/protocols/application_protocol/interface/ApplicationProtocolService.hh"
#include <memory>

namespace honeybadger::communication::protocols::interface
{
class ApplicationProtocolServiceFactory
{
  public:
    virtual ~ApplicationProtocolServiceFactory() = default;
    virtual std::unique_ptr<ApplicationProtocolService> create() = 0;
};
} // namespace honeybadger::communication::protocols::interface