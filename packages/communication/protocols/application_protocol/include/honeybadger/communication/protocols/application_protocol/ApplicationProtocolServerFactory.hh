#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/protocols/protocols/interface/ProtocolServer.hh"
#include <memory>

namespace honeybadger::communication::protocols
{
class ApplicationProtocolServerFactory
{
  public:
    ApplicationProtocolServerFactory(const honeybadger::common::types::Endpoint &endpoint);
    std::unique_ptr<interface::ProtocolServer> create();

  private:
    honeybadger::common::types::Endpoint endpoint_;
};
} // namespace honeybadger::communication::protocols