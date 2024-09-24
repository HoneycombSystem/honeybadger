#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/server/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::server::interface
{
class ServerFactory
{
  public:
    virtual ~ServerFactory() = default;
    virtual std::unique_ptr<interface::Server> create() = 0;
};
} // namespace honeybadger::communication::server::interface