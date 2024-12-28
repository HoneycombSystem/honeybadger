#include "honeybadger/communication/network/sctp/ConnectedSocket.hh"
#include "honeybadger/common/types/network/Payload.hh"
#include "honeybadger/communication/network/Logger.hh"
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
    if(sctpSocket_)
    {
        return sctpSocket_->isClosed();
    }
    return true;
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
    try
    {
    while(not isClosed())
    {
        auto recv = co_await receive();
        // co_await send(recv);
    }
    }
    catch(const boost::system::system_error &e)
    {
        if(e.code() == boost::asio::error::eof || e.code() == boost::asio::error::connection_reset)
        {
            INFO_LOG( "Clien disconnected gracefully.\n");
        }
        else
        {
            INFO_LOG( "Error with client {}" ,e.what());
        }
    }
    closeSctpSocketAndResetPointer();
    co_return;
}
RESTORE_WARNINGS

void ConnectedSocket::closeSctpSocketAndResetPointer()
{
    INFO_LOG("Closing SCTP socket");
    if(sctpSocket_ and not sctpSocket_->isClosed())
    {
        sctpSocket_.reset();
    }
}
} // namespace honeybadger::communication::network
