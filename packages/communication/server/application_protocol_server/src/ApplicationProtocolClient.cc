#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolClient.hh"
#include "honeybadger/communication/network/socket/interface/ConnectedSocket.hh"

namespace honeybadger::communication::server
{
ApplicationProtocolClient::ApplicationProtocolClient(std::unique_ptr<network::interface::ConnectedSocket> connectedSocket) :
    connectedSocket_(std::move(connectedSocket)), isRunning_(false), id_("12321312312")
{
}

ApplicationProtocolClient::~ApplicationProtocolClient()
{
}

void ApplicationProtocolClient::run()
{
    isRunning_ = true;
    while(isRunning_)
    {
        // Do something
    }
}

bool ApplicationProtocolClient::isRunning() const
{
    return isRunning_;
}

common::types::Uuid ApplicationProtocolClient::getId() const
{
    return id_;
}
} // namespace honeybadger::communication::server
