#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServerFactory.hh"
#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServer.hh"
#include "honeybadger/communication/protocols/Logger.hh"
#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServerFactory.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolServerFactory::ApplicationProtocolServerFactory(
    const honeybadger::common::types::Endpoint &endpoint) :
    endpoint_(endpoint)
{
}

std::unique_ptr<interface::ProtocolServer> ApplicationProtocolServerFactory::create()
{
    TRACE_LOG("Creating ApplicationProtocolServer with endpoint: ");
    auto server = server::ApplicationProtocolServerFactory(endpoint_).create();
    return std::make_unique<ApplicationProtocolServer>(std::move(server));
}
} // namespace honeybadger::communication::protocols