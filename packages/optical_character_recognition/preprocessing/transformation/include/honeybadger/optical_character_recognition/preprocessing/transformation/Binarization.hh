#pragma once
#include "honeybadger/optical_character_recognition/preprocessing/transformation/interface/Transformation.hh"

namespace honeybadger::optical_character_recognition::preprocessing::transformation
{
class Binarization : public interface::Transformation
{
  private:
    std::uint8_t threshold_;
    std::uint8_t maxValue_;

  public:
    Binarization(std::uint8_t, std::uint8_t);
    image::format::types::raw_image_t apply(const image::format::types::raw_image_t&) const override;
};
} // namespace honeybadger::optical_character_recognition::preprocessing::transformation