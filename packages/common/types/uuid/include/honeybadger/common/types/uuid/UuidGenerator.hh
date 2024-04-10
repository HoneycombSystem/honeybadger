#pragma once
#include <string>
#include "honeybadger/common/types/uuid/Uuid.hh"
namespace honeybadger::common::types
{
class UuidGenerator
{
  public:
    Uuid generate() const;
};
} // namespace honeybadger::common::types