#include "honeybadger/optical_character_recognition/preprocessing/transformation/Binarization.hh"
#include <gtest/gtest.h>

namespace
{
using honeybadger::optical_character_recognition::image::format::types::byte_t;
using honeybadger::optical_character_recognition::image::format::types::raw_image_t;
using threshold_t = std::uint8_t;
using max_value_t = std::uint8_t;

struct BinarizationParam
{
    threshold_t threshold;
    max_value_t maxValue;
    raw_image_t input;
    raw_image_t expected;
};

class BinarizationParamTest : public ::testing::TestWithParam<BinarizationParam>
{
};

TEST_P(BinarizationParamTest, BinarizationTest)
{
    const auto& [threshold, maxValue, input, expected] = GetParam();
    honeybadger::optical_character_recognition::preprocessing::transformation::Binarization binarization(
        threshold,
        maxValue);
    const auto result = binarization.apply(input);
    ASSERT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    BinarizationTest,
    BinarizationParamTest,
    ::testing::Values(
        BinarizationParam{
            threshold_t(128),
            max_value_t(255),
            {0, 2, 4, 8, 16, 32, 64, 128, 255},
            {0, 0, 0, 0, 0,  0,  0,  0,   255}
},
        BinarizationParam{threshold_t(128), max_value_t(255), {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}},
        BinarizationParam{threshold_t(128),
                          max_value_t(255),
                          {255, 255, 255, 255, 255, 255, 255, 255},
                          {255, 255, 255, 255, 255, 255, 255, 255}},
        BinarizationParam{threshold_t(128), max_value_t(128), {0, 1, 2, 3, 4, 5, 6, 7}, {0, 0, 0, 0, 0, 0, 0, 0}}));
} // namespace