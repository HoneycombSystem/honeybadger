#pragma once
#include "honeybadger/optical_character_recognition/preprocessing/region_of_interest/RegionsNames.hh"

namespace honeybadger::optical_character_recognition::preprocessing::interface
{
class RegionOfInterestDetector
{
  public:
    virtual ~RegionOfInterestDetector() = default;
    virtual RegionsNames recognize() = 0;
};
} // namespace honeybadger::optical_character_recognition::preprocessing::interface