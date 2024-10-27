#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/protocols/protocols/interface/Protocol.hh"
#include "honeybadger/communication/protocols/protocols/interface/ProtocolFactory.hh"
#include <memory>

namespace honeybadger::communication::protocols
{
class ApplicationProtocolFactory : public interface::ProtocolFactory
{
  public:
    ApplicationProtocolFactory(const honeybadger::common::types::Endpoint &);
    std::unique_ptr<interface::Protocol> create();

  private:
    honeybadger::common::types::Endpoint endpoint_;
};
} // namespace honeybadger::communication::protocols