#pragma once
#include "honeybadger/common/types/strong_type/StrongType.hh"
#include "honeybadger/optical_character_recognition/preprocessing/transformation/interface/Transformation.hh"

namespace honeybadger::optical_character_recognition::preprocessing::transformation
{
using Threshold = common::types::StrongType<std::uint8_t, struct ThresholdTag>;
using MaxValue = common::types::StrongType<std::uint8_t, struct MaxValueTag>;

class Binarization : public interface::Transformation
{
  private:
    Threshold threshold_;
    MaxValue maxValue_;

  public:
    Binarization(Threshold, MaxValue);
    image::format::types::RawImage apply(const image::format::types::RawImage &) const override;
};
} // namespace
  // honeybadger::optical_character_recognition::preprocessing::transformation