#include "honeybadger/communication/sctp/broker/Broker.hh"

namespace honeybadger::communication::sctp
{
Broker::Broker(const common::types::Endpoint& endpoint, std::unique_ptr<interface::Sctp> sctp) :
    endpoint_(endpoint), sctp_(std::move(sctp))
{
}

void Broker::start()
{
    sctp_->bind(endpoint_);
    sctp_->listen();
    sctp_->accept();
}

void Broker::stop()
{
    sctp_->close();
}
} // namespace honeybadger::communication::sctp