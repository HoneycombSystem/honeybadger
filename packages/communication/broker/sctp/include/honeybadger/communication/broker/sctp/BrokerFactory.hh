#pragma once
#include "honeybadger/communication/broker/sctp/interface/BrokerFactory.hh"

namespace honeybadger::communication::broker
{
class BrokerFactory : public interface::BrokerFactory
{
  public:
    std::unique_ptr<interface::Broker> create(const common::types::Endpoint &) override;
};
} // namespace honeybadger::communication::broker