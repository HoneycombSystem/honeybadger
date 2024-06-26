#pragma once
#include "honeybadger/communication/network/sctp/interface/AsyncClientSocket.hh"

namespace honeybadger::communication::network
{
class SctpClient : public interface::ClientSender
{

  public:
    SctpClient(interface::AsyncClientSocket &&);

    bool send(const common::types::Payload &) override;
    void receive();
    void run() override;
    
  private:
    std::unique_ptr<interface::AsyncClientSocket> clientSocket_;
};
} // namespace honeybadger::communication::network