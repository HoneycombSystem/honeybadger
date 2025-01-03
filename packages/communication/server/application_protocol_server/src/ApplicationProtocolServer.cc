#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServer.hh"
#include "honeybadger/communication/server/Logger.hh"

namespace honeybadger::communication::server
{
ApplicationProtocolServer::ApplicationProtocolServer(std::unique_ptr<network::interface::ServerSocket>
                                                         asyncServerSocket,
                                                     const common::types::Endpoint &endpoint) :
    asyncServerSocket_(std::move(asyncServerSocket)),
    sctpEventManager_()
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