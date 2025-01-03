#pragma once
#include "honeybadger/common/types/uuid/UUID.hh"
#include "honeybadger/communication/network/sctp/SctpEventManager.hh"
#include "honeybadger/communication/network/socket/interface/ServerSocket.hh"
#include "honeybadger/communication/server/server/interface/Server.hh"
#include <memory>
#include <unordered_map>

namespace honeybadger::communication::server
{
class ApplicationProtocolServer : public interface::Server
{
  public:
    ApplicationProtocolServer(std::unique_ptr<network::interface::ServerSocket>, const common::types::Endpoint &);
    ~ApplicationProtocolServer();
    void run() override;
    void stop() override;

  private:
    struct UuidHash
    {
        std::size_t operator()(const honeybadger::common::types::Uuid &uuid) const
        {
            return std::hash<std::string>{}(uuid.value());
        }
    };

    std::unique_ptr<network::interface::ServerSocket> asyncServerSocket_;
    network::SctpEventManager sctpEventManager_;
    std::unordered_map<common::types::Uuid, std::shared_ptr<network::interface::ConnectedSocket>, UuidHash>
        connectedSockets_{};
};
} // namespace honeybadger::communication::server