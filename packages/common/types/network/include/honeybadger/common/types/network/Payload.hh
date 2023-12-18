#pragma once
#include "honeybadger/common/types/strong_type/StrongType.hh"
#include <cstdint>
#include <vector>

namespace honeybadger::common::types
{
using Payload = StrongType<std::vector<std::uint8_t>, struct PayloadTag>;
} // namespace honeybadger::common::types
