#include "honeybadger/communication/broker/application_protocol_broker/ApplicationProtocolBroker.hh"
#include "honeybadger/communication/network/server/interface/Server.hh"

namespace honeybadger::communication::broker
{
ApplicationProtocolBroker::ApplicationProtocolBroker(std::unique_ptr<network::interface::Server> server) :
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