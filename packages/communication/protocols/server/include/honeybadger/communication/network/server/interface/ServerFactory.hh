#pragma once
#include "honeybadger/communication/network/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::network::interface
{
class ServerFactory
{
  public:
    virtual ~ServerFactory() = default;
    virtual std::unique_ptr<Server> create() = 0;
};
} // namespace honeybadger::communication::network::interface