#include "honeybadger/optical_character_recognition/preprocessing/transformation/Binarization.hh"

namespace honeybadger::optical_character_recognition::preprocessing::transformation
{
Binarization::Binarization(std::uint8_t threshold, std::uint8_t maxValue) : threshold_(threshold), maxValue_(maxValue)
{
}

image::format::types::raw_image_t Binarization::apply(const image::format::types::raw_image_t& image) const
{
    image::format::types::raw_image_t result;
    result.reserve(image.size());
    for(auto pixel: image)
    {
        result.push_back(pixel > threshold_ ? maxValue_ : 0);
    }
    return result;
}
} // namespace honeybadger::optical_character_recognition::preprocessing::transformation
