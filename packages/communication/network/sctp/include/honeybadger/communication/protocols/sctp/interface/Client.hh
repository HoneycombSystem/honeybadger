#pragma once
#include "honeybadger/common/types/network/Payload.hh"

namespace honeybadger::communication::protocols::interface
{
class Client
{
  public:
    virtual ~Client() = default;
    virtual bool send(const common::types::Payload &) = 0;
    virtual void run() = 0;
};
} // namespace honeybadger::communication::protocols::interface