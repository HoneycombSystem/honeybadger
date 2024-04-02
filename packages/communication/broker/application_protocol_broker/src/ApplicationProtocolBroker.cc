#include "honeybadger/communication/broker/application_protocol_broker/ApplicationProtocolBroker.hh"
#include "honeybadger/communication/protocols/server/interface/Server.hh"

namespace honeybadger::communication::broker
{
ApplicationProtocolBroker::ApplicationProtocolBroker(std::unique_ptr<protocols::interface::Server> server) :
    server_(std::move(server))
{
}

ApplicationProtocolBroker::~ApplicationProtocolBroker()
{
    server_->stop();
}

void ApplicationProtocolBroker::run()
{
    server_->run();
}
} // namespace honeybadger::communication::broker