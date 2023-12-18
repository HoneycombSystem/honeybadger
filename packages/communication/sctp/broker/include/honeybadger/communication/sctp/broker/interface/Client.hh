#pragma once
#include "honeybadger/common/types/network/Payload.hh"

namespace honeybadger::communication::sctp::interface
{
class Client
{
  public:
    virtual ~Client() = default;
    virtual bool send(const common::types::Payload &) = 0;
    virtual void start() = 0;
};
} // namespace honeybadger::communication::sctp::interface