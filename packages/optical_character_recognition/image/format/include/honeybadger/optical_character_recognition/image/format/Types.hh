#pragma once
#include <cstdint>
#include <vector>

namespace honeybadger::optical_character_recognition::image::format::types
{
using byte_t = std::uint8_t;
using raw_image_t = std::vector<byte_t>;
using height_t = std::uint32_t;
using width_t = std::uint32_t;
enum class ColorSpace
{
    binary = 0,
    grayscale = 1,
    rgb = 3
};
} // namespace honeybadger::optical_character_recognition::image::types