#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolFactory.hh"
#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocol.hh"
#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServerFactory.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolFactory::ApplicationProtocolFactory(const honeybadger::common::types::Endpoint &endpoint) :
    endpoint_(endpoint)
{
}

std::unique_ptr<interface::Protocol> ApplicationProtocolFactory::create()
{
    auto protocolServer = ApplicationProtocolServerFactory(endpoint_).create();
    return std::make_unique<ApplicationProtocol>(std::move(protocolServer));
}
} // namespace honeybadger::communication::protocols