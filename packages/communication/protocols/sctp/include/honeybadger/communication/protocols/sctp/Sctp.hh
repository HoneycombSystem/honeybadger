#pragma once
#include "honeybadger/communication/network/socket/interface/Serversocket.hh"
#include <boost/asio.hpp>

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::protocols
{
class Sctp : public network::interface::ServerSocket
{
  private:
    using Protocol = boost::asio::generic::stream_protocol;
    boost::asio::io_context ioContext_;
    boost::asio::basic_socket_acceptor<Protocol> acceptor_;
    Protocol::socket socket_;

  public:
    Sctp();
    bool bind(const common::types::Endpoint &) override;
    bool listen() override;
    bool accept() override;
    bool close() override;
};
} // namespace honeybadger::communication::protocols