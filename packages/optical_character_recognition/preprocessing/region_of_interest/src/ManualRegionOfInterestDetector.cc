#include "honeybadger/optical_character_recognition/preprocessing/region_of_interest/ManualRegionOfInterestDetector.hh"

namespace honeybadger::optical_character_recognition::preprocessing
{
ManualRegionOfInterestDetector::ManualRegionOfInterestDetector(const RegionsNames& regionsNames) :
    regionsNames_(regionsNames)
{
}

RegionsNames ManualRegionOfInterestDetector::recognize()
{
    return regionsNames_;
}
} // namespace honeybadger::optical_character_recognition::preprocessing