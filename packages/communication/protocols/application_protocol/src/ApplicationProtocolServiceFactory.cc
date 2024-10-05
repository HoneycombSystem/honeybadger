#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServiceFactory.hh"
#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolService.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolServiceFactory::ApplicationProtocolServiceFactory()
{
}

std::unique_ptr<interface::ApplicationProtocolService> ApplicationProtocolServiceFactory::create()
{
    return std::make_unique<ApplicationProtocolService>();
}
} // namespace honeybadger::communication::protocols