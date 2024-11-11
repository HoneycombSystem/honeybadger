#include "honeybadger/communication/network/sctp/ConnectedSocket.hh"
#include "honeybadger/common/types/network/Payload.hh"
#include "honeybadger/communication/network/sctp/SctpSocket.hh"

namespace honeybadger::communication::network
{
ConnectedSocket::ConnectedSocket(std::shared_ptr<SctpSocket> sctpSocket) : sctpSocket_(std::move(sctpSocket))
{
}

ConnectedSocket::~ConnectedSocket()
{
    closeSctpSocketAndResetPointer();
}

void ConnectedSocket::close()
{
    closeSctpSocketAndResetPointer();
}

bool ConnectedSocket::isClosed() const
{
    return sctpSocket_ == nullptr or sctpSocket_->isClosed();
}

DISABLE_SWITCH_DEFAULT_WARNING_DUE_TO_BOOST_COROUTINES

common::coroutines::Task<void> ConnectedSocket::send(const common::types::Payload &)
{
    // [[maybe_unused]] auto temp = sctpSocket_->send(payload);
    co_return;
}

common::coroutines::Task<common::types::Payload> ConnectedSocket::receive()
{
    co_return common::types::Payload{};
}

RESTORE_WARNINGS

void ConnectedSocket::closeSctpSocketAndResetPointer()
{
    if(sctpSocket_ and not sctpSocket_->isClosed())
    {
        sctpSocket_->close();
        sctpSocket_.reset();
    }
}
} // namespace honeybadger::communication::network
