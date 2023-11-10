#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/sctp/broker/interface/Broker.hh"
#include <memory>

namespace honeybadger::communication::sctp::interface
{
class BrokerFactory
{
  public:
    virtual ~BrokerFactory() = default;
    virtual std::unique_ptr<interface::Broker> create(const common::types::Endpoint &) = 0;
};
} // namespace honeybadger::communication::sctp::interface