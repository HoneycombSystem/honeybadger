#pragma once
#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolClient.hh"
#include "honeybadger/communication/server/server/interface/ClientManager.hh"
#include "honeybadger/communication/server/server/interface/ClientManagerMatcher.hh"
#include <honeybadger/common/types/uuid/Uuid.hh>
#include <memory>
#include <unordered_map>

namespace honeybadger::communication::server
{
class ApplicationProtocolClientManager : public interface::ClientManager
{
  public:
    ApplicationProtocolClientManager();
    ~ApplicationProtocolClientManager();
    void addClient(std::shared_ptr<interface::Client>) override;
    void removeClient(const common::types::Uuid &) override;
    virtual std::vector<std::shared_ptr<interface::Client>>
    filter(const interface::ClientManagerMatcher &) const override;

  private:
    struct UuidHasher
    {
        std::size_t operator()(const common::types::Uuid &uuid) const
        {
            return std::hash<std::string>()(uuid.value());
        }
    };

    std::unordered_map<common::types::Uuid, std::shared_ptr<interface::Client>, UuidHasher> clients_;
};
} // namespace honeybadger::communication::server