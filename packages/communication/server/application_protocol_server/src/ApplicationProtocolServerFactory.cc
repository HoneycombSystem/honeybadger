#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServerFactory.hh"
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/network/sctp/SctpAsyncServerSocket.hh"
#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServer.hh"
#include <memory>

namespace honeybadger::communication::server
{
ApplicationProtocolServerFactory::ApplicationProtocolServerFactory(const common::types::Endpoint &endpoint) :
    endpoint_(endpoint)
{
}

std::unique_ptr<interface::Server> ApplicationProtocolServerFactory::create()
{
    std::unique_ptr<network::interface::AsyncServerSocket> serverSocket =
        std::make_unique<network::SctpAsyncServerSocket>(endpoint_);
    std::unique_ptr<interface::Server> server = std::make_unique<ApplicationProtocolServer>(std::move(serverSocket));
    // return std::make_unique<ApplicationProtocolServer>(std::move(server));
    return server;
}
} // namespace honeybadger::communication::server