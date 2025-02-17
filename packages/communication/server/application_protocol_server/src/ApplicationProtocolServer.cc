#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServer.hh"
#include "honeybadger/communication/server/Logger.hh"

namespace honeybadger::communication::server
{
ApplicationProtocolServer::ApplicationProtocolServer(std::unique_ptr<network::interface::ServerSocket>
                                                         asyncServerSocket,
                                                     const common::types::Endpoint &endpoint,
                                                     std::unique_ptr<interface::ClientManager>
                                                         clientManager) :
    asyncServerSocket_(std::move(asyncServerSocket)),
    clientManager_(std::move(clientManager)), sctpEventManager_()
{
    asyncServerSocket_->bind(endpoint);
}

ApplicationProtocolServer::~ApplicationProtocolServer()
{
}

void ApplicationProtocolServer::run()
{
    INFO_LOG("Starting server on endpoint: ");
    asyncServerSocket_->listen();
}

void ApplicationProtocolServer::stop()
{
    if(not asyncServerSocket_->isClosed())
    {
        asyncServerSocket_->close();
    }
}
} // namespace honeybadger::communication::server