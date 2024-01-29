#pragma once
#include "honeybadger/communication/sctp/broker/interface/BrokerFactory.hh"

namespace honeybadger::communication::sctp
{
class BrokerFactory : public interface::BrokerFactory
{
  public:
    std::unique_ptr<interface::Broker> create(const common::types::Endpoint &) override;
};
} // namespace honeybadger::communication::sctp