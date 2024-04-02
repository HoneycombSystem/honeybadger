#pragma once
#include <memory>
#include "honeybadger/communication/protocols/server/interface/Server.hh"
#include "honeybadger/communication/network/socket/interface/ServerSocket.hh"

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::protocols
{
class SctpServer : public interface::Server
{
    private:
      std::unique_ptr<network::interface::ServerSocket> serverSocket_;

    public:
      SctpServer(std::unique_ptr<network::interface::ServerSocket>);
      virtual ~SctpServer() = default;
      virtual bool run() override;
      virtual bool stop() override;
};
} // namespace honeybadger::communication::protocols