#pragma once
#include "honeybadger/common/types/Payload.hh"
#include <cstddef>

namespace honeybadger::common::types
{
using Payload;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network ::interface
{
class SenderSocket
{
  public:
    virtual ~SenderSocket() = default;
    virtual std::size_t send(const common::types::Payload &) = 0;
};
} // namespace honeybadger::communication::network::interface