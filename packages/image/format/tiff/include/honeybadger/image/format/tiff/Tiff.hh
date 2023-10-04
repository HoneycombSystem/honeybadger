#pragma once
#include "honeybadger/image/types/Image.hh"

namespace honeybadger::image::format
{
class Tiff
{
  private:
    types::raw_image_t raw_image_;
    types::width_t width_;
    types::height_t height_;
    types::ColorSpace colorSpace_;

  public:
    Tiff(types::raw_image_t&&, types::width_t, types::height_t, types::ColorSpace);
    ~Tiff() = default;
};
} // namespace honeybadger::image::format