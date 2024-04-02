#pragma once
#include "honeybadger/communication/protocols/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::protocols::interface
{
class SctpServerFactory : public ServerFactory
{
  private:
    common::types::Endpoint endpoint_;
  public:
    SctpServerFactory(const common::types::Endpoint &);
    std::unique_ptr<Server> create() override;
};
} // namespace honeybadger::communication::protocols::interface