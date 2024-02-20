#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/broker/sctp/interface/Broker.hh"
#include <memory>

namespace honeybadger::communication::broker::interface
{
class BrokerFactory
{
  public:
    virtual ~BrokerFactory() = default;
    virtual std::unique_ptr<interface::Broker> create(const common::types::Endpoint &) = 0;
};
} // namespace honeybadger::communication::broker::interface