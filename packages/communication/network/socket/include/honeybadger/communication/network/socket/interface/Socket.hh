#pragma once
#include <cstddef>

namespace honeybadger::communication::network ::interface
{
class Socket
{
  public:
    virtual ~Socket() = default;
    virtual bool close() = 0;
};
} // namespace honeybadger::communication::network::interface