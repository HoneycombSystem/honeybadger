#pragma once
#include "honeybadger/common/types/strong_type/StrongType.hh"
#include <cstdint>
#include <vector>

namespace honeybadger::optical_character_recognition::preprocessing
{
class Position
{
  public:
    using X = common::types::StrongType<std::uint32_t, struct Xtag>;
    using Y = common::types::StrongType<std::uint32_t, struct Ytag>;

  private:
    const X x_;
    const Y y_;

  public:
    Position(X, Y);

    friend auto operator<=>(const Position &lhs, const Position &rhs) = default;

    X x() const;
    Y y() const;
};

struct Coordinate
{
    using LeftTop = common::types::StrongType<Position, struct LeftTopTag>;
    using RightTop = common::types::StrongType<Position, struct RightTopTag>;
    using LeftBottom = common::types::StrongType<Position, struct LeftBottomTag>;
    using RightBottom = common::types::StrongType<Position, struct RightBottomTag>;

    Coordinate(LeftTop, RightTop, LeftBottom, RightBottom);
    friend auto operator<=>(const Coordinate &lhs, const Coordinate &rhs) = default;

    const LeftTop leftTop;
    const RightTop rightTop;
    const LeftBottom leftBottom;
    const RightBottom rightBottom;
};

} // namespace honeybadger::optical_character_recognition::preprocessing