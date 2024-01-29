#pragma once
#include "Socket.hh"

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network::interface
{
class ServerSocket : public Socket
{
  public:
    virtual ~ServerSocket() = default;
    virtual bool bind(const common::types::Endpoint &) = 0;
    virtual bool listen() = 0;
    virtual bool accept() = 0;
};
} // namespace honeybadger::communication::network::interface