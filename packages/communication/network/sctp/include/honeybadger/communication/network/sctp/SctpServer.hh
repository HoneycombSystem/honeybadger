#pragma once
#include "honeybadger/communication/network/interface/interface/Server.hh"
#include "honeybadger/communication/network/sctp/SctpSocket.hh"
#include <memory>

namespace honeybadger::communication::network
{
class SctpServer : public interface::Server
{
  private:
  std::unique_ptr<SctpSocket> socket_;
  public:
    SctpServer(const SctpServer&) = delete;
    SctpServer& operator=(const SctpServer&) = delete;
    SctpServer(SctpServer&&) = delete;
    SctpServer& operator=(SctpServer&&) = delete;

    SctpServer(std::unique_ptr<SctpSocket>&& socket);
    ~SctpServer();

    void run() override;
    void stop() override;
};
} // namespace honeybadger::communication::network::sctp