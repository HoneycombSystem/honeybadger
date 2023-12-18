#include "honeybadger/communication/sctp/broker/Client.hh"
#include "honeybadger/communication/sctp/Logger.hh"
#include <array>
#include <utility>

namespace honeybadger::communication::sctp
{
Client::Client(Protocol::socket &&socket) : socket_{std::move(socket)}
{
    // socket.non_blocking(true);
}

void Client::start()
{
    receive();
}

void Client::moveOffset(std::size_t bytes)
{
    if(offset_ + bytes < buffer_.size())
    {
        offset_ += bytes;
    }
    else
    {
        DEBUG_LOG("Offset is at the end of the buffer(size: {}), resetting offset position", buffer_.size());
        offset_ = 0;
    }
}

void Client::receiveHeader()
{
    boost::asio::async_read(socket_,
                            boost::asio::buffer(&bodySize_, sizeof(bodySize_)),
                            [this](boost::system::error_code ec, std::size_t bytesTransferred)
                            {
        TRACE_LOG("SCTP socket received {} bytes", bytesTransferred);
        if(!ec)
        {
            TRACE_LOG("Received data: {}", bodySize_);
            receiveBody();
        }
        else
        {
            WARN_LOG("SCTP socket receive failed: {}", ec.message());
        }
    });
}

void Client::receiveBody()
{
    boost::asio::async_read(socket_,
                            boost::asio::buffer(buffer_.data() + offset_, bodySize_),
                            [this](boost::system::error_code ec, std::size_t bytesTransferred)
                            {
        TRACE_LOG("SCTP socket received {} bytes", bytesTransferred);
        if(!ec)
        {
            auto payload{std::string{buffer_.data() + offset_, bytesTransferred}};
            moveOffset(bytesTransferred);

            INFO_LOG("Received payload: {}", payload);

            receiveHeader();
        }
        else
        {
            WARN_LOG("SCTP socket receive failed: {}", ec.message());
        }
    });
}

void Client::receive()
{
    receiveHeader();
}

// bool sendHeader(const common::types::Payload &);
// bool sendBody(const common::types::Payload &);
bool Client::send(const common::types::Payload &payload)
{
    socket_.async_send(boost::asio::buffer(payload.value().data(), payload.value().size()),
                       [this](boost::system::error_code ec, std::size_t)
                       {
        INFO_LOG("SCTP socket sent");
        if(!ec)
        {
            // INFO_LOG("SCTP socket sent {} bytes", buffer_.size());
        }
        else
        {
            WARN_LOG("SCTP socket send failed: {}", ec.message());
        }
    });
    return false;
}
} // namespace honeybadger::communication::sctp