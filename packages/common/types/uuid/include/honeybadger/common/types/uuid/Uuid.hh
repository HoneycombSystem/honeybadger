#pragma once
#include <string>

namespace honeybadger::common::types
{
class Uuid
{
  private:
    std::string uuid_;

  public:
    Uuid(const std::string& uuid) : uuid_{uuid}
    {
    }

    friend bool operator==(const Uuid& lhs, const Uuid& rhs)
    {
        return lhs.uuid_ == rhs.uuid_;
    }

    friend bool operator!=(const Uuid& lhs, const Uuid& rhs)
    {
        return lhs.uuid_ != rhs.uuid_;
    }

    // ToDo(miekicki): think about string_view
    std::string value() const
    {
        return uuid_;
    }
};
} // namespace honeybadger::common::types