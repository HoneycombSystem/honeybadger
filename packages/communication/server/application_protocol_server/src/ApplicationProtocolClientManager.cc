#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolClientManager.hh"

namespace honeybadger::communication::server
{
ApplicationProtocolClientManager::ApplicationProtocolClientManager() : clients_()
{
}

ApplicationProtocolClientManager::~ApplicationProtocolClientManager()
{
}

void ApplicationProtocolClientManager::addClient(std::shared_ptr<interface::Client> client)
{
    clients_.insert({client->getId(), client});
}

void ApplicationProtocolClientManager::removeClient(const common::types::Uuid &uuid)
{
    clients_.erase(uuid);
}

std::vector<std::shared_ptr<interface::Client>>
ApplicationProtocolClientManager::filter(const interface::ClientManagerMatcher &matcher) const
{
    std::vector<std::shared_ptr<interface::Client>> result;
    for(const auto &[uuid, client]: clients_)
    {
        if(matcher(*client))
        {
            result.push_back(client);
        }
    }
    return result;
}
} // namespace honeybadger::communication::server