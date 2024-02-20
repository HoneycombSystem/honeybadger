#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/broker/sctp/interface/Broker.hh"
#include "honeybadger/communication/protocols/sctp/Sctp.hh"
#include <memory>

namespace honeybadger::communication::broker
{
class SctpBroker : public interface::Broker
{
  private:
    common::types::Endpoint endpoint_;
    std::unique_ptr<network::interface::ServerSocket> sctp_;

  public:
    SctpBroker(const common::types::Endpoint& endpoint, std::unique_ptr<network::interface::ServerSocket> sctp);
    void start() override;
    void stop() override;
};
} // namespace honeybadger::communication::broker