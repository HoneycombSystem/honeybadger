#pragma once

namespace honeybadger::common::types
{
template<typename T, typename Tag>
class StrongType
{
  public:
    template<typename... Args>
    explicit StrongType(Args... values) : value_(values...)
    {
    }

    StrongType(const StrongType &) = default;
    StrongType(StrongType &&) = default;
    StrongType &operator=(const StrongType &) = default;
    StrongType &operator=(StrongType &&) = default;

    ~StrongType() = default;

    friend auto operator<=>(const StrongType &lhs, const StrongType &rhs) = default;

    T value() const
    {
        return value_;
    }

  private:
    T value_;
};
} // namespace honeybadger::common::types