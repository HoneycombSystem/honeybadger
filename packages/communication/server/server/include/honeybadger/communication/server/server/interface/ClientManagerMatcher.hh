#pragma once
#include "honeybadger/communication/server/server/interface/Client.hh"

namespace honeybadger::communication::server::interface
{
class ClientManagerMatcher
{
  public:
    virtual ~ClientManagerMatcher() = default;
    virtual bool operator()(const interface::Client &item) const = 0;
};
} // namespace honeybadger::communication::server::interface
