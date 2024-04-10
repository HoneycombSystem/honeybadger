#include "honeybadger/common/types/uuid/Uuid.hh"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace honeybadger::common::types
{
std::string Uuid::generate() const
{
    static boost::uuids::random_generator gen;
    return boost::uuids::to_string(gen());
}
} // namespace honeybadger::common::types