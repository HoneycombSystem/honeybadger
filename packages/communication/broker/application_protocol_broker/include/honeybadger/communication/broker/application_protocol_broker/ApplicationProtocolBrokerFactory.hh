#pragma once
#include "honeybadger/communication/broker/broker/interface/BrokerFactory.hh"

namespace honeybadger::communication::broker
{
class ApplicationProtocolBrokerFactory : public interface::BrokerFactory
{
  private:
    common::types::Endpoint endpoint_;
  public:
    ApplicationProtocolBrokerFactory(const common::types::Endpoint &);
    std::unique_ptr<interface::Broker> create() override;
};
} // namespace honeybadger::communication::broker