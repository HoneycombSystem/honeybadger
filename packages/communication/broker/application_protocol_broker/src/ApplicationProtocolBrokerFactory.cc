#include "honeybadger/communication/broker/application_protocol_broker/ApplicationProtocolBrokerFactory.hh"
#include "honeybadger/communication/broker/application_protocol_broker/ApplicationProtocolBroker.hh"
#include "honeybadger/communication/network/sctp/Sctp.hh"
#include <memory>

namespace honeybadger::communication::broker
{
ApplicationProtocolBrokerFactory::ApplicationProtocolBrokerFactory(const common::types::Endpoint &endpoint) :
    endpoint_(endpoint)
{
}

std::unique_ptr<interface::Broker> ApplicationProtocolBrokerFactory::create()
{
    std::unique_ptr<network::interface::ServerSocket> serverSocket = std::make_unique<network::Sctp>(endpoint_);
    std::unique_ptr<protocols::interface::Server> server =
        std::make_unique<protocols::SctpServer>(std::move(serverSocket));
    return std::make_unique<ApplicationProtocolBroker>(std::move(server));
}
} // namespace honeybadger::communication::broker