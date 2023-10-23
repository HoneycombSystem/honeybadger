#include "honeybadger/optical_character_recognition/preprocessing/transformation/Binarization.hh"
#include <gtest/gtest.h>

namespace
{
using honeybadger::optical_character_recognition::image::format::types::Byte;
using honeybadger::optical_character_recognition::image::format::types::RawImage;
using honeybadger::optical_character_recognition::preprocessing::transformation::MaxValue;
using honeybadger::optical_character_recognition::preprocessing::transformation::Threshold;

struct BinarizationParam
{
    Threshold threshold;
    MaxValue maxValue;
    RawImage input;
    RawImage expected;
};

class BinarizationParamTest : public ::testing::TestWithParam<BinarizationParam>
{
};

TEST_P(BinarizationParamTest, BinarizationTest)
{
    const auto &[threshold, maxValue, input, expected] = GetParam();
    using honeybadger::optical_character_recognition::preprocessing::transformation::Binarization;
    Binarization binarization(threshold, maxValue);
    const auto result = binarization.apply(input);
    ASSERT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    BinarizationTest, BinarizationParamTest,
    ::testing::Values(
        BinarizationParam{
            Threshold(128),
            MaxValue(255),
            RawImage{Byte(0), Byte(2), Byte(4), Byte(8), Byte(16), Byte(32), Byte(64), Byte(128), Byte(255)},
            RawImage{Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(255)}},
        BinarizationParam{Threshold(128),
                          MaxValue(255),
                          {Byte(0), Byte(0), Byte(128), Byte(127), Byte(129), Byte(0), Byte(0), Byte(0)},
                          {Byte(0), Byte(0), Byte(0), Byte(0), Byte(255), Byte(0), Byte(0), Byte(0)}},
        BinarizationParam{Threshold(128),
                          MaxValue(255),
                          {Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0)},
                          {Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0)}},
        BinarizationParam{Threshold(128),
                          MaxValue(255),
                          {Byte(255), Byte(255), Byte(255), Byte(255), Byte(255), Byte(255), Byte(255), Byte(255)},
                          {Byte(255), Byte(255), Byte(255), Byte(255), Byte(255), Byte(255), Byte(255), Byte(255)}},
        BinarizationParam{Threshold(128),
                          MaxValue(128),
                          {Byte(0), Byte(1), Byte(2), Byte(3), Byte(4), Byte(5), Byte(6), Byte(7)},
                          {Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0), Byte(0)}}));
} // namespace