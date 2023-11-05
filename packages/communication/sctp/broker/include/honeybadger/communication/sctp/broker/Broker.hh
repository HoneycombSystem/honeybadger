#pragma once
#include "honeybadger/communication/sctp/broker/interface/Broker.hh"
#include "honeybadger/communication/sctp/broker/interface/Sctp.hh"
#include <memory>

namespace honeybadger::communication::sctp
{
class Broker : public interface::Broker
{
  private:
    common::types::Endpoint endpoint_;
    std::unique_ptr<interface::Sctp> sctp_;

  public:
    Broker(const common::types::Endpoint& endpoint, std::unique_ptr<interface::Sctp> sctp);
    void start() override;
    void stop() override;
};
} // namespace honeybadger::communication::sctp