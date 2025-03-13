#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServerFactory.hh"
#include "honeybadger/common/io_context/io_context/AsioIOContext.hh"
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/network/sctp/SctpServerSocket.hh"
#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolClientManager.hh"
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
    std::shared_ptr<common::io_context::IOContextManager> ioContextManager =
        std::make_shared<common::io_context::IOContextManager>();
    std::unique_ptr<network::interface::ServerSocket> serverSocket =
        std::make_unique<network::SctpServerSocket>(ioContextManager);
    std::unique_ptr<interface::ClientManager> clientManager = std::make_unique<ApplicationProtocolClientManager>();
    std::unique_ptr<interface::Server> server = std::make_unique<ApplicationProtocolServer>(ioContextManager,
                                                                                            std::move(serverSocket),
                                                                                            endpoint_,
                                                                                            std::move(clientManager));
    return server;
}
} // namespace honeybadger::communication::server