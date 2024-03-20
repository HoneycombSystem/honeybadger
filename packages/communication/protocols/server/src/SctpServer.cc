#include "honeybadger/communication/network/server/SctpServer.hh"
#include "honeybadger/communication/protocols/sctp/Sctp.hh"

namespace honeybadger::communication::network
{
SctpServer::SctpServer(const common::types::Endpoint& endpoint) : serverSocket_(std::make_unique<Sctp>())
{
    serverSocket_->bind(endpoint);
    serverSocket_->listen();
}

bool SctpServer::run()
{
    serverSocket_->accept();
}

bool SctpServer::stop()
{
    serverSocket_->close();
}
} // namespace honeybadger::communication::network