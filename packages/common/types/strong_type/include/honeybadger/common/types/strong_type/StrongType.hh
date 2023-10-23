#pragma once

namespace honeybadger::common::types
{
template<typename T, typename Tag>
class StrongType
{
  public:
    explicit StrongType(T const &value) : value_(value)
    {
    }

    T value() const
    {
        return value_;
    }

    explicit operator T() const
    {
        return value_;
    }

    friend auto operator<=>(const StrongType &lhs, const StrongType &rhs) = default;

  private:
    T value_;
};
} // namespace honeybadger::common::types