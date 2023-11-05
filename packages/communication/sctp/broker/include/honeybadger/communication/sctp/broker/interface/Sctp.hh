#pragma once
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/common/types/network/Payload.hh"

namespace honeybadger::communication::sctp::interface
{
class Sctp
{
  public:
    virtual ~Sctp() = default;
    virtual bool bind(const common::types::Endpoint&) = 0;
    virtual bool listen() = 0;
    virtual bool accept() = 0;
    virtual bool send(const common::types::Payload&) = 0;
    virtual common::types::Payload recv() = 0;
    virtual bool close() = 0;
};
} // namespace honeybadger::communication::sctp::interface