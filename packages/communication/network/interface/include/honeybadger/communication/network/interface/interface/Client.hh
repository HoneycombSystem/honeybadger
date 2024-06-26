#pragma once
#include "honeybadger/common/types/network/Payload.hh"
#include "honeybadger/common/types/uuid/Uuid.hh"

namespace honeybadger::communication::network::interface
{
class Client
{
  public:
    virtual ~Client() = default;
    virtual common::types::Uuid getIdentifier() = 0;
    virtual void send(const common::types::Payload&) = 0;
    virtual common::types::Payload receive() = 0;
}
} // namespace honeybadger::communication::network::interface