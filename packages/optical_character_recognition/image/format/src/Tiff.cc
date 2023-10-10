#include "honeybadger/optical_character_recognition/image/format/Tiff.hh"

namespace honeybadger::optical_character_recognition::image::format
{
Tiff::Tiff(types::raw_image_t&& raw_image, types::width_t width, types::height_t height, types::ColorSpace colorSpace) :
    raw_image_(std::move(raw_image)), width_(width), height_(height), colorSpace_(colorSpace)
{
}

types::raw_image_t Tiff::data() const noexcept
{
    return raw_image_;
}

types::width_t Tiff::width() const noexcept
{
    return width_;
}

types::height_t Tiff::height() const noexcept
{
    return height_;
}

types::ColorSpace Tiff::colorSpace() const noexcept
{
    return colorSpace_;
}
} // namespace honeybadger::optical_character_recognition::image::format