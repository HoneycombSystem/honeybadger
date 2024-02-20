#include "honeybadger/communication/broker/sctp/SctpBroker.hh"
#include "honeybadger/communication/network/socket/interface/ServerSocket.hh"

namespace honeybadger::communication::broker
{
SctpBroker::SctpBroker(const common::types::Endpoint& endpoint,
                       std::unique_ptr<network::interface::ServerSocket>
                           sctp) :
    endpoint_(endpoint),
    sctp_(std::move(sctp))
{
}

void SctpBroker::start()
{
    sctp_->bind(endpoint_);
    sctp_->listen();
    sctp_->accept();
}

void SctpBroker::stop()
{
    sctp_->close();
}
} // namespace honeybadger::communication::broker