#include "honeybadger/communication/protocols/server/SctpServer.hh"
#include "honeybadger/communication/network/sctp/Sctp.hh"

namespace honeybadger::communication::protocols
{
SctpServer::SctpServer(std::unique_ptr<network::interface::ServerSocket> serverSocket) : serverSocket_(std::move(serverSocket))
{
    serverSocket_->listen();
}

bool SctpServer::run()
{
    return serverSocket_->accept();
}

bool SctpServer::stop()
{
    return serverSocket_->close();
}
} // namespace honeybadger::communication::protocols