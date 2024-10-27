#pragma once
#include "honeybadger/communication/protocols/protocols/interface/ProtocolService.hh"
#include <memory>

namespace honeybadger::communication::protocols::interface
{
class ProtocolServiceFactory
{
  public:
    virtual ~ProtocolServiceFactory() = default;
    virtual std::unique_ptr<ProtocolService> create() = 0;
};
} // namespace honeybadger::communication::protocols::interface