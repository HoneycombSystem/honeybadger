#pragma once
#include "honeybadger/communication/sctp/broker/interface/Client.hh"
#include <boost/asio.hpp>

namespace honeybadger::communication::sctp
{
class Client : public interface::Client
{
  private:
    using Protocol = boost::asio::generic::stream_protocol;
    Protocol::socket socket_;
    std::array<char, 1024> buffer_{};
    std::size_t offset_{0};

    void moveOffset(std::size_t);
    void receiveHeader();
    void receiveBody();
    bool sendHeader(const common::types::Payload &);
    bool sendBody(const common::types::Payload &);
    void receive();

    std::size_t bodySize_{0};

  public:
    Client(Protocol::socket &&);
    bool send(const common::types::Payload &) override;
    void start() override;
};
} // namespace honeybadger::communication::sctp