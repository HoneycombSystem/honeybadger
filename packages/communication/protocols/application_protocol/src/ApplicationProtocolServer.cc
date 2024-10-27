#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServer.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolServer::ApplicationProtocolServer(std::unique_ptr<server::interface::Server> server) :
    server_(std::move(server))
{
}

void ApplicationProtocolServer::run()
{
}
} // namespace honeybadger::communication::protocols