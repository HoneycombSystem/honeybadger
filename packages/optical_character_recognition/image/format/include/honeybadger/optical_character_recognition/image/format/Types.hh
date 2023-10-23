#pragma once
#include "honeybadger/common/types/strong_type/StrongType.hh"
#include <cstdint>
#include <vector>

namespace honeybadger::optical_character_recognition::image::format::types
{
using Byte = common::types::StrongType<std::uint8_t, struct ByteTag>;
using RawImage = std::vector<Byte>;
using Height = common::types::StrongType<std::uint32_t, struct HeightTag>;
using Width = common::types::StrongType<std::uint32_t, struct WidthTag>;
enum class ColorSpace
{
    binary = 0,
    grayscale = 1,
    rgb = 3
};
} // namespace honeybadger::optical_character_recognition::image::format::types