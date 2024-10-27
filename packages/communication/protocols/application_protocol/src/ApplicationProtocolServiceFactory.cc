#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServiceFactory.hh"
#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolFactory.hh"
#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolService.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolServiceFactory::ApplicationProtocolServiceFactory(
    const honeybadger::common::types::Endpoint &endpoint) :
    endpoint_(endpoint)
{
}

std::unique_ptr<interface::ProtocolService> ApplicationProtocolServiceFactory::create()
{
    auto applicationProtocol = ApplicationProtocolFactory(endpoint_).create();
    return std::make_unique<ApplicationProtocolService>(std::move(applicationProtocol));
}
} // namespace honeybadger::communication::protocols