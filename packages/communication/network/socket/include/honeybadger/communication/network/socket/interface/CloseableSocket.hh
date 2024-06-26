#pragma once

namespace honeybadger::communication::network::interface
{
struct CloseableSocket
{
        virtual ~CloseableSocket() = default;
        virtual bool close() = 0;
};
}