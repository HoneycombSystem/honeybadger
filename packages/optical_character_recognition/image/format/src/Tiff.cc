#include "honeybadger/optical_character_recognition/image/format/Tiff.hh"

namespace honeybadger::optical_character_recognition::image::format
{
Tiff::Tiff(types::RawImage &&rawImage, types::Width width, types::Height height, types::ColorSpace colorSpace) :
    rawImage_(std::move(rawImage)), width_(width), height_(height), colorSpace_(colorSpace)
{
}

types::RawImage Tiff::data() const noexcept
{
    return rawImage_;
}

types::Width Tiff::width() const noexcept
{
    return width_;
}

types::Height Tiff::height() const noexcept
{
    return height_;
}

types::ColorSpace Tiff::colorSpace() const noexcept
{
    return colorSpace_;
}
} // namespace honeybadger::optical_character_recognition::image::format