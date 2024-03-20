#include "honeybadger/communication/broker/application_protocol_broker/ApplicationProtocolBrokerFactory.hh"
#include "honeybadger/communication/broker/application_protocol_broker/ApplicationProtocolBroker.hh"
#include "honeybadger/communication/network/server/SctpServer.hh"
#include <memory>

namespace honeybadger::communication::broker
{
ApplicationProtocolBrokerFactory::ApplicationProtocolBrokerFactory(const common::types::Endpoint &endpoint) : endpoint_(endpoint) {}

std::unique_ptr<interface::Broker> ApplicationProtocolBrokerFactory::create()
{
    std::unique_ptr<network::interface::Server> server = std::make_unique<network::SctpServer>(endpoint_);
    return std::make_unique<ApplicationProtocolBroker>(std::move(server));
}
} // namespace honeybadger::communication::broker