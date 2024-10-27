// #pragma once
// #include "honeybadger/communication/network/socket/interface/ClientSocket.hh"
// #include "honeybadger/communication/network/socket/interface/ReceiverSocket.hh"
// #include "honeybadger/communication/network/socket/interface/SenderSocket.hh"
// #include "honeybadger/communication/network/socket/interface/ServerSocket.hh"
// #include "honeybadger/communication/network/socket/interface/CloseableSocket.hh"
// #include <boost/asio.hpp>

// namespace honeybadger::common::types
// {
// class Payload;
// class Endpoint;
// } // namespace honeybadger::common::types

// namespace honeybadger::communication::network
// {
// class SctpSocket :
//     public interface::CloseableSocket,
//     public interface::ServerSocket,
//     public interface::ClientSocket,
//     public interface::ReceiverSocket,
//     public interface::SenderSocket
// {
//   public:
//     SctpSocket(const SctpSocket &) = delete;
//     SctpSocket(SctpSocket &&) = delete;
//     SctpSocket &operator=(const SctpSocket &) = delete;
//     SctpSocket &operator=(SctpSocket &&) = delete;

//     SctpSocket();
//     virtual ~SctpSocket();

//     bool bind(const common::types::Endpoint &) override;
//     bool listen() override;
//     bool accept() override;
//     void receive() override;
//     void send(const common::types::Payload &) override;
//     bool connect(const common::types::Endpoint &) override;
//     bool close() override;

//   private:
//     using Protocol = boost::asio::generic::stream_protocol;
//     boost::asio::io_context ioContext_;
//     boost::asio::basic_socket_acceptor<Protocol> acceptor_;
//     Protocol::socket socket_;

//     void selectSctpProtocolForAcceptor();
//     bool closeConnectionOnBothSides();
// };
// } // namespace honeybadger::communication::network