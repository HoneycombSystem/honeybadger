#pragma once
#include "honeybadger/communication/sctp/broker/interface/Sctp.hh"
#include <boost/asio.hpp>

namespace honeybadger::communication::sctp
{
class Sctp : public interface::Sctp
{
  private:
    // using protocol = asio::generic::seq_packet_protocol;
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
} // namespace honeybadger::communication::sctp