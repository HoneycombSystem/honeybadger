#include "honeybadger/communication/protocols/sctp/Client.hh"
#include "honeybadger/communication/protocols/Logger.hh"
#include <array>
#include <chrono>
#include <utility>

namespace
{
bool isError(const boost::system::error_code &ec)
{
    if(ec == boost::asio::error::eof)
    {
        INFO_LOG("SCTP socket closed");
        return true;
    }
    if(ec)
    {
        WARN_LOG("SCTP socket error: {}", ec.message());
        return true;
    }
    return false;
}
} // namespace

namespace honeybadger::communication::protocols
{
Client::Client(Protocol::socket &&socket) : socket_{std::move(socket)}
{
}

void Client::run()
{
    receive();
}

void Client::receive()
{
    boost::asio::async_read(socket_,
                            boost::asio::buffer(&buffer_, buffer_.size()),
                            boost::asio::transfer_at_least(4),
                            [this](boost::system::error_code ec, std::size_t bytesTransferred)
                            {
        if(not isError(ec))
        {
            TRACE_LOG("SCTP socket received payload: {} with size: {}", buffer_.data(), bytesTransferred);
            receive();
        }
    });
}

bool Client::send(const common::types::Payload &payload)
{
    socket_.async_send(boost::asio::buffer(payload.value().data(), payload.value().size()),
                       [this](boost::system::error_code ec, std::size_t)
                       {
        if(not isError(ec))
        {
            // INFO_LOG("SCTP socket sent {} bytes", buffer_.size());
        }
    });
    return false;
}
} // namespace honeybadger::communication::protocols