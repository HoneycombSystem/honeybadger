#pragma once
#include "honeybadger/optical_character_recognition/image/format/Types.hh"

namespace honeybadger::optical_character_recognition::preprocessing::transformation::interface
{
class Transformation
{
  public:
    virtual ~Transformation() = default;
    virtual image::format::types::raw_image_t apply(const image::format::types::raw_image_t& image) const = 0;
};
} // namespace honeybadger::optical_character_recognition::preprocessing::transformation::interface