#pragma once
#include "honeybadger/optical_character_recognition/image/format/interface/Image.hh"

namespace honeybadger::optical_character_recognition::image::format
{
class Tiff : public interface::Image
{
  private:
    types::RawImage rawImage_;
    types::Width width_;
    types::Height height_;
    types::ColorSpace colorSpace_;

  public:
    Tiff(types::RawImage &&, types::Width, types::Height, types::ColorSpace);
    virtual types::RawImage data() const noexcept override;
    virtual types::Width width() const noexcept override;
    virtual types::Height height() const noexcept override;
    virtual types::ColorSpace colorSpace() const noexcept override;
};
} // namespace honeybadger::optical_character_recognition::image::format