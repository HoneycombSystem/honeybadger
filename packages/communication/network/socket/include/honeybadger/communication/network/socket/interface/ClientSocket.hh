#pragma once
#include "ReceiverSocket.hh"
#include "SenderSocket.hh"
#include "Socket.hh"

namespace honeybadger::common::types
{
class Payload;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network ::interface
{
class ClientSocket : public Socket, public Sender, public Receiver
{
  public:
    virtual ~ClientSocket() = default;
};
} // namespace honeybadger::communication::network::interface