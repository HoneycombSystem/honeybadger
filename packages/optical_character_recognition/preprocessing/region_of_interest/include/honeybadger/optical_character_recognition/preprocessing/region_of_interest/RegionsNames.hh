#pragma once
#include "honeybadger/optical_character_recognition/preprocessing/region_of_interest/Coordinate.hh"
#include <map>
#include <variant>

namespace honeybadger::optical_character_recognition::preprocessing
{
enum class InvoiceRegionName
{
    date,
    invoiceNumber,
    seller,
    buyer,
    servicesOrGoods
};

using InvoiceRegionOfInterest = std::map<InvoiceRegionName, Coordinate>;
using RegionsNames = std::variant<InvoiceRegionOfInterest>;
} // namespace honeybadger::optical_character_recognition::preprocessing