#include "honeybadger/communication/network/sctp/SctpServerSocket.hh"
#include "honeybadger/common/types/network/Endpoint.hh"
#include "honeybadger/communication/network/sctp/SctpSocket.hh"

namespace honeybadger::communication::network
{
SctpServerSocket::SctpServerSocket(const common::types::Endpoint &endpoint) :
    endpoint_(endpoint), sctpSocket_(std::make_unique<SctpSocket>())
{
}

SctpServerSocket::~SctpServerSocket()
{
    closeSctpSocketAndResetPointer();
}

bool SctpServerSocket::bind(const common::types::Endpoint &)
{
    return sctpSocket_->bind(endpoint_);
}

bool SctpServerSocket::listen()
{
    return sctpSocket_->listen();
}

DISABLE_SWITCH_DEFAULT_WARNING_DUE_TO_BOOST_COROUTINES

common::coroutines::Task<std::unique_ptr<interface::ConnectedSocket>> SctpServerSocket::accept()
{
    co_return co_await sctpSocket_->accept();
}

RESTORE_WARNINGS

void SctpServerSocket::close()
{
    closeSctpSocketAndResetPointer();
}

bool SctpServerSocket::isClosed() const
{
    return sctpSocket_ == nullptr or sctpSocket_->isClosed();
}

void SctpServerSocket::closeSctpSocketAndResetPointer()
{
    if(sctpSocket_ and not sctpSocket_->isClosed())
    {
        sctpSocket_->close();
        sctpSocket_.reset(nullptr);
    }
}
} // namespace honeybadger::communication::network