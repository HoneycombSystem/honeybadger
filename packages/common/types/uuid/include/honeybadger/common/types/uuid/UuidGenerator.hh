#pragma once
#include "honeybadger/common/types/uuid/Uuid.hh"
#include <string>

namespace honeybadger::common::types
{
class UuidGenerator
{
  public:
    Uuid generate() const;
};
} // namespace honeybadger::common::types