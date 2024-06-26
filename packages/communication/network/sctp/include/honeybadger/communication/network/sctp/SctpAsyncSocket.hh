#pragma once
#include <boost/asio.hpp>
#include "honeybadger/communication/network/socket/interface/AsyncClientSocket.hh"
#include "honeybadger/communication/network/socket/interface/AsyncServerSocket.hh"
#include "honeybadger/communication/network/socket/interface/AsyncReceiverSocket.hh"
#include "honeybadger/communication/network/socket/interface/CloseableSocket.hh"
#include "honeybadger/communication/network/socket/interface/AsyncSenderSocket.hh"

namespace honeybadger::common::types
{
class Payload;
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network
{
class SctpAsyncSocket : public interface::CloseableSocket, public interface::AsyncServerSocket, public interface::AsyncClientSocket, public interface::AsyncReceiverSocket, public interface::AsyncSenderSocket
{
    public:
        SctpAsyncSocket();
        virtual ~SctpAsyncSocket();

        bool bind(const common::types::Endpoint &) override;
        bool listen() override;
        bool accept() override;
        void receive() override;
        void send(const common::types::Payload &) override;
        bool connect(const common::types::Endpoint &) override;
        bool close() override;

    private:
      using Protocol = boost::asio::generic::stream_protocol;
      boost::asio::io_context ioContext_;
      boost::asio::basic_socket_acceptor<Protocol> acceptor_;
      Protocol::socket socket_;

};
}