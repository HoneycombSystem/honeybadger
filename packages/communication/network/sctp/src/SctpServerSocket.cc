#include "honeybadger/communication/network/sctp/SctpServerSocket.hh"

namespace honeybadger::communication::network
{
SctpServerSocket::SctpServerSocket(const common::types::Endpoint &)
{
}

SctpServerSocket::~SctpServerSocket()
{
}

bool SctpServerSocket::bind(const common::types::Endpoint &)
{
    return false;
}

bool SctpServerSocket::listen()
{
    return false;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-default"

common::coroutines::Task<void> SctpServerSocket::accept()
{
    co_return;
}

#pragma GCC diagnostic pop

void SctpServerSocket::close()
{
}

bool SctpServerSocket::isClosed() const
{
    return false;
}
} // namespace honeybadger::communication::network