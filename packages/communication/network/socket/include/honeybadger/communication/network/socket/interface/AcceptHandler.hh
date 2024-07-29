#pragma once

namespace honeybadger::communication::network::interface
{
struct AcceptHandler
{
    virtual ~AcceptHandler() = default;
    virtual void onAccept() = 0;
};
}