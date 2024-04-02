#pragma once
#include "honeybadger/communication/protocols/server/interface/Server.hh"
#include <memory>

namespace honeybadger::communication::protocols::interface
{
class ServerFactory
{
  public:
    virtual ~ServerFactory() = default;
    virtual std::unique_ptr<Server> create() = 0;
};
} // namespace honeybadger::communication::protocols::interface