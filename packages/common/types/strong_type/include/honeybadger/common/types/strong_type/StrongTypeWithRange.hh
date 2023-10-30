#pragma once

namespace honeybadger::common::types
{
template<typename T, typename Tag, typename min, typename max>
class StrongTypeWithRange
{
  public:
    explicit StrongTypeWithRange(T const &v) : value_(v)
    {
        if(value_ < min::value)
        {
            throw std::runtime_error("Value is less than min");
        }
        if(value_ > max::value)
        {
            throw std::runtime_error("Value is greater than max");
        }
    }

    explicit StrongTypeWithRange(T &&value) : value_(std::move(value))
    {
    }

    T value() const
    {
        return value_;
    }

    explicit operator T() const
    {
        return value;
    }

    friend auto operator<=>(const StrongTypeWithRange &lhs, const StrongTypeWithRange &rhs) = default;

  private:
    T value_;
};
} // namespace honeybadger::common::types