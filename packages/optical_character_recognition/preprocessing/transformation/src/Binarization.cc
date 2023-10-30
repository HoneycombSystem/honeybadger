#include "honeybadger/optical_character_recognition/preprocessing/transformation/Binarization.hh"
#include <algorithm>

namespace honeybadger::optical_character_recognition::preprocessing::transformation
{
Binarization::Binarization(Threshold threshold, MaxValue maxValue) : threshold_(threshold), maxValue_(maxValue)
{
}

image::format::types::RawImage Binarization::apply(const image::format::types::RawImage &image) const
{
    using image::format::types::RawImage, image::format::types::Byte;
    RawImage result;
    result.reserve(image.size());
    std::for_each(image.begin(),
                  image.end(),
                  [&result, this](const auto &pixel)
                  {
        const auto value = Byte(pixel.value() > threshold_.value() ? maxValue_.value() : static_cast<std::uint8_t>(0));
        result.push_back(value);
    });
    return result;
}
} // namespace
  // honeybadger::optical_character_recognition::preprocessing::transformation
