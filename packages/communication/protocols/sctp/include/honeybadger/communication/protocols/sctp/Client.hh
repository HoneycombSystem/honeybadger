#pragma once
#include "honeybadger/communication/protocols/sctp/interface/Client.hh"
#include <boost/asio.hpp>

namespace
{
constexpr std::size_t operator"" _gigabyte(unsigned long long int x)
{
    return x * 1024 * 1024 * 1024;
}
} // namespace

namespace honeybadger::communication::protocols
{
class Client : public interface::Client
{
  private:
    using Protocol = boost::asio::generic::stream_protocol;
    Protocol::socket socket_;
    static const std::size_t maxBufferSize_{2_gigabyte};
    std::array<char, maxBufferSize_> buffer_{0};

    void receive();

  public:
    Client(Protocol::socket &&);
    bool send(const common::types::Payload &) override;
    void start() override;
};
} // namespace honeybadger::communication::protocols