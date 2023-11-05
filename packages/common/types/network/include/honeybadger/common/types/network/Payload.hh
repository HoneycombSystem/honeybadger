#pragma once
#include "honeybadger/common/types/strong_type/StrongType.hh"
#include <cstdint>

namespace honeybadger::common::types
{
using Payload = StrongType<std::uint8_t, struct PayloadTag>;
} // namespace honeybadger::common::types
