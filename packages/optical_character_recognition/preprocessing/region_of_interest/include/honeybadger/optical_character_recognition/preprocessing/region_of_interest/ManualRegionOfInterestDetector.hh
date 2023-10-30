#pragma once
#include "honeybadger/optical_character_recognition/preprocessing/region_of_interest/interface/RegionOfInterestDetector.hh"

namespace honeybadger::optical_character_recognition::preprocessing
{
class ManualRegionOfInterestDetector : public interface::RegionOfInterestDetector
{
  private:
    RegionsNames regionsNames_;

  public:
    ManualRegionOfInterestDetector(const RegionsNames &);
    RegionsNames recognize() override;
};
} // namespace honeybadger::optical_character_recognition::preprocessing