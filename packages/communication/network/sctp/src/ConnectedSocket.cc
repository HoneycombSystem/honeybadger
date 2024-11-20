#include "honeybadger/communication/network/sctp/ConnectedSocket.hh"
#include "honeybadger/common/types/network/Payload.hh"
#include "honeybadger/communication/network/sctp/SctpSocket.hh"
#include "honeybadger/communication/network/Logger.hh"

namespace honeybadger::communication::network
{
ConnectedSocket::ConnectedSocket(std::shared_ptr<SctpSocket> sctpSocket) : sctpSocket_(std::move(sctpSocket))
{
    INFO_LOG("ConnectedSocket::ConnectedSocket()");
}

ConnectedSocket::~ConnectedSocket()
{
    INFO_LOG("ConnectedSocket::~ConnectedSocket()");
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

common::coroutines::Task<void> ConnectedSocket::send(const common::types::Payload &payload)
{
    co_await sctpSocket_->send(payload);
    co_return;
}

common::coroutines::Task<common::types::Payload> ConnectedSocket::receive()
{
    co_return co_await sctpSocket_->receive();
}

common::coroutines::Task<void> ConnectedSocket::run()
{
    while(true)
    {
        //co_await sctpSocket_->sync();
        auto recv = co_await receive();
        auto recvValue = recv.value();
        std::reverse(recvValue.begin(), recvValue.end());
        recv = common::types::Payload(recvValue);
        co_await send(recv);
    }
    co_return;
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
