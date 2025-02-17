#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolFactory.hh"
#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocol.hh"
#include "honeybadger/communication/protocols/Logger.hh"
#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServerFactory.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolFactory::ApplicationProtocolFactory(const honeybadger::common::types::Endpoint &endpoint) :
    endpoint_(endpoint)
{
}

std::unique_ptr<interface::Protocol> ApplicationProtocolFactory::create()
{
    TRACE_LOG("Creating ApplicationProtocol with endpoint: ");
    std::unique_ptr<server::interface::Server> protocolServer =
        honeybadger::communication::server::ApplicationProtocolServerFactory(endpoint_).create();
    return std::make_unique<ApplicationProtocol>(std::move(protocolServer));
}
} // namespace honeybadger::communication::protocols