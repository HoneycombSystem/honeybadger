#pragma once
#include "honeybadger/communication/network/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::network::interface
{
class SctpServerFactory : public ServerFactory
{
  private:
    common::types::Endpoint endpoint_;
  public:
    SctpServerFactory(const common::types::Endpoint &);
    std::unique_ptr<Server> create() override;
};
} // namespace honeybadger::communication::network::interface