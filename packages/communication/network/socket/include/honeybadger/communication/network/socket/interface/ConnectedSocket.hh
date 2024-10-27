#pragma once
#include "honeybadger/communication/network/socket/interface/CloseableSocket.hh"
#include "honeybadger/communication/network/socket/interface/ReceiverSocket.hh"
#include "honeybadger/communication/network/socket/interface/SenderSocket.hh"

namespace honeybadger::communication::network::interface
{
class ConnectedSocket : public CloseableSocket, public SenderSocket, public ReceiverSocket
{
  public:
    virtual ~ConnectedSocket() = default;
};
} // namespace honeybadger::communication::network::interface
