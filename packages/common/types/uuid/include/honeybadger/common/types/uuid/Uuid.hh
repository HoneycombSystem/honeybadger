#pragma once
#include <string>

namespace honeybadger::common::types
{
class Uuid
{
  public:
    std::string generate() const;
};
} // namespace honeybadger::common::types