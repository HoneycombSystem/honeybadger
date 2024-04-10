#include "honeybadger/common/types/uuid/UuidGenerator.hh"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace honeybadger::common::types
{
Uuid UuidGenerator::generate() const
{
    static boost::uuids::random_generator gen;
    return Uuid(boost::uuids::to_string(gen()));
}
} // namespace honeybadger::common::types