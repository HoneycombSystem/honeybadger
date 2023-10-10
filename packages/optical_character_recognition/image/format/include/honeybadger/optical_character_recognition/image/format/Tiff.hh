#pragma once
#include "honeybadger/optical_character_recognition/image/format/interface/Image.hh"

namespace honeybadger::optical_character_recognition::image::format
{
class Tiff : public interface::Image
{
  private:
    types::raw_image_t raw_image_;
    types::width_t width_;
    types::height_t height_;
    types::ColorSpace colorSpace_;

  public:
    Tiff(types::raw_image_t&&, types::width_t, types::height_t, types::ColorSpace);
    virtual types::raw_image_t data() const noexcept override;
    virtual types::width_t width() const noexcept override;
    virtual types::height_t height() const noexcept override;
    virtual types::ColorSpace colorSpace() const noexcept override;
};
} // namespace honeybadger::optical_character_recognition::image::format