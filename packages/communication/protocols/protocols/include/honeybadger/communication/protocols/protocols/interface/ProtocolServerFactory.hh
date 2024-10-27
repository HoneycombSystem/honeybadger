#pragma once
#include "honeybadger/communication/protocols/protocols/interface/ProtocolServer.hh"
#include <memory>

namespace honeybadger::communication::protocols::interface
{
class ProtocolServerFactory
{
  public:
    virtual ~ProtocolServerFactory() = default;
    virtual std::unique_ptr<ProtocolServer> create() = 0;
};
} // namespace honeybadger::communication::protocols::interface