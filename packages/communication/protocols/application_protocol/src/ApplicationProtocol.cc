#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocol.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocol::ApplicationProtocol(std::unique_ptr<server::interface::Server> protocolServer) :
    protocolServer_(std::move(protocolServer))
{
}

void ApplicationProtocol::run()
{
    protocolServer_->run();
}

void ApplicationProtocol::onMessage()
{
}
} // namespace honeybadger::communication::protocols