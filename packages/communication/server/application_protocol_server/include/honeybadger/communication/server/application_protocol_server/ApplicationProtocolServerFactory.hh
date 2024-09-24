#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/server/server/interface/ServerFactory.hh"

namespace honeybadger::communication::server
{
class ApplicationProtocolServerFactory : public interface::ServerFactory
{
  private:
    common::types::Endpoint endpoint_;

  public:
    ApplicationProtocolServerFactory(const common::types::Endpoint &);
    std::unique_ptr<interface::Server> create() override;
};
} // namespace honeybadger::communication::server