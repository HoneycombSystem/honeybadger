#include "honeybadger/communication/sctp/broker/BrokerFactory.hh"
#include "honeybadger/communication/sctp/broker/Broker.hh"
#include "honeybadger/communication/sctp/broker/Sctp.hh"
#include <memory>

namespace honeybadger::communication::sctp
{
std::unique_ptr<interface::Broker> BrokerFactory::create(const common::types::Endpoint &endpoint)
{
    std::unique_ptr<interface::Sctp> sctp = std::make_unique<Sctp>();
    return std::make_unique<Broker>(endpoint, std::move(sctp));
}
} // namespace honeybadger::communication::sctp