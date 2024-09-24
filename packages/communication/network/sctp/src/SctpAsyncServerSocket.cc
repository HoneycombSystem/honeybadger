#include "honeybadger/communication/network/sctp/SctpAsyncServerSocket.hh"

namespace honeybadger::communication::network
{
SctpAsyncServerSocket::SctpAsyncServerSocket(const common::types::Endpoint &)
{
}

SctpAsyncServerSocket::~SctpAsyncServerSocket()
{
}

bool SctpAsyncServerSocket::bind(const common::types::Endpoint &)
{
    return false;
}

bool SctpAsyncServerSocket::listen()
{
    return false;
}

common::coroutines::Task<interface::CloseableSocket> SctpAsyncServerSocket::accept()
{
    return common::coroutines::Task<interface::CloseableSocket>();
}
} // namespace honeybadger::communication::network