#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/broker/broker/interface/Broker.hh"
#include "honeybadger/communication/network/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::broker
{
class ApplicationProtocolBroker : public interface::Broker
{
  private:
    std::unique_ptr<network::interface::Server> server_;

  public:
    ApplicationProtocolBroker(std::unique_ptr<network::interface::Server>);
    ~ApplicationProtocolBroker();
    void run() override;
};
} // namespace honeybadger::communication::broker