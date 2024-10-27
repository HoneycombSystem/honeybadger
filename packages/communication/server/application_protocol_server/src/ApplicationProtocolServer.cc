#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServer.hh"

namespace honeybadger::communication::server
{
ApplicationProtocolServer::ApplicationProtocolServer(
    std::unique_ptr<network::interface::ServerSocket> asyncServerSocket) :
    asyncServerSocket_(std::move(asyncServerSocket))
{
}

ApplicationProtocolServer::~ApplicationProtocolServer()
{
}

void ApplicationProtocolServer::start()
{
}

void ApplicationProtocolServer::stop()
{
}
} // namespace honeybadger::communication::server