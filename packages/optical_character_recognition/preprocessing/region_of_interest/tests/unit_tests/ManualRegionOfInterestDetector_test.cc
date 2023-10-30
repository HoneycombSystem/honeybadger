#include "honeybadger/optical_character_recognition/preprocessing/region_of_interest/ManualRegionOfInterestDetector.hh"
#include <gtest/gtest.h>

TEST(ManualRegionOfInterestDetectorTest, inputPassByConstructorShouldBeEqualToOutputFromRecognizeMethod)
{
    using namespace honeybadger::optical_character_recognition::preprocessing;
    InvoiceRegionOfInterest invoiceRegionOfInterest;
    invoiceRegionOfInterest.emplace(InvoiceRegionName::date,
                                    Coordinate(Coordinate::LeftTop(Position::X(0), Position::Y(0)),
                                               Coordinate::RightTop(Position::X(50), Position::Y(0)),
                                               Coordinate::LeftBottom(Position::X(50), Position::Y(50)),
                                               Coordinate::RightBottom(Position::X(0), Position::Y(50))));
    invoiceRegionOfInterest.emplace(InvoiceRegionName::invoiceNumber,
                                    Coordinate(Coordinate::LeftTop(Position::X(50), Position::Y(0)),
                                               Coordinate::RightTop(Position::X(100), Position::Y(0)),
                                               Coordinate::LeftBottom(Position::X(100), Position::Y(50)),
                                               Coordinate::RightBottom(Position::X(50), Position::Y(50))));
    RegionsNames regionsNames = invoiceRegionOfInterest;
    honeybadger::optical_character_recognition::preprocessing::ManualRegionOfInterestDetector
        manualRegionOfInterestDetector(regionsNames);
    EXPECT_EQ(regionsNames, manualRegionOfInterestDetector.recognize());
}
