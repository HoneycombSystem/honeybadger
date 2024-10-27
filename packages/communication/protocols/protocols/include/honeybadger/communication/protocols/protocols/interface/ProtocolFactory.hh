#pragma once
#include "honeybadger/communication/protocols/protocols/interface/Protocol.hh"
#include <memory>

namespace honeybadger::communication::protocols::interface
{
class ProtocolFactory
{
  public:
    virtual ~ProtocolFactory() = default;
    virtual std::unique_ptr<Protocol> create() = 0;
};
} // namespace honeybadger::communication::protocols::interface