#pragma once
#include "honeybadger/optical_character_recognition/image/format/Types.hh"

namespace honeybadger::optical_character_recognition::image::format::interface
{
class Image
{
  public:
    virtual ~Image() = default;
    virtual types::raw_image_t data() const noexcept = 0;
    virtual types::width_t width() const noexcept = 0;
    virtual types::height_t height() const noexcept = 0;
    virtual types::ColorSpace colorSpace() const noexcept = 0;
};
} // namespace honeybadger::optical_character_recognition::image::format::interface