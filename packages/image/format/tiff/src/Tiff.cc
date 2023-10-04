#include "honeybadger/image/format/tiff/Tiff.hh"

namespace honeybadger::image::format
{
Tiff::Tiff(types::raw_image_t&& raw_image, types::width_t width, types::height_t height, types::ColorSpace colorSpace) :
    raw_image_(std::move(raw_image)), width_(width), height_(height), colorSpace_(colorSpace)
{
}
} // namespace honeybadger::image::format