#pragma once
#include <memory>
#include "honeybadger/communication/network/server/interface/Server.hh"
#include "honeybadger/communication/network/socket/interface/Serversocket.hh"

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network
{
class SctpServer : public interface::Server
{
    private:
      std::unique_ptr<interface::ServerSocket> serverSocket_;

    public:
      SctpServer(std::unique_ptr<interface::ServerSocket>);
      virtual ~SctpServer() = default;
      virtual bool run() override;
      virtual bool stop() override;

};
} // namespace honeybadger::communication::network