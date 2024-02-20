#include "honeybadger/communication/broker/sctp/BrokerFactory.hh"
#include "honeybadger/communication/broker/sctp/SctpBroker.hh"
#include "honeybadger/communication/protocols/sctp/Sctp.hh"
#include <memory>

namespace honeybadger::communication::broker
{
std::unique_ptr<interface::Broker> BrokerFactory::create(const common::types::Endpoint &endpoint)
{
    std::unique_ptr<network::interface::ServerSocket> sctp = std::make_unique<protocols::Sctp>();
    return std::make_unique<SctpBroker>(endpoint, std::move(sctp));
}
} // namespace honeybadger::communication::broker