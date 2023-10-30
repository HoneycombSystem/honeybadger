#include "honeybadger/optical_character_recognition/preprocessing/region_of_interest/Coordinate.hh"

namespace honeybadger::optical_character_recognition::preprocessing
{
Position::Position(X x, Y y) : x_(x), y_(y)
{
}

Position::X Position::x() const
{
    return x_;
}

Position::Y Position::y() const
{
    return y_;
}

Coordinate::Coordinate(Coordinate::LeftTop lt, Coordinate::RightTop rt, Coordinate::LeftBottom lb,
                       Coordinate::RightBottom rb) :
    leftTop(lt),
    rightTop(rt), leftBottom(lb), rightBottom(rb)
{
}
} // namespace honeybadger::optical_character_recognition::preprocessing