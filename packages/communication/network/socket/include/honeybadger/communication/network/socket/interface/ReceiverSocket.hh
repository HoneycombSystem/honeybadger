#pragma once
#include "honeybadger/common/types/Payload.hh"

namespace honeybadger::communication::network ::interface
{
class ReceiverSocket
{
  public:
    virtual ~ReceiverSocket() = default;
    virtual common::types::Payload receive() = 0;
};
} // namespace honeybadger::communication::network::interface