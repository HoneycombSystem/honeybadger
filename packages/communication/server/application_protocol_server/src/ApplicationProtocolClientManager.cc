#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolClientManager.hh"
#include "honeybadger/communication/server/Logger.hh"
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
    auto [it, b] =clients_.insert({client->getId(), client});
    if(!b)
    {
        ERROR_LOG("Client with id: " + client->getId().value() + " already exists!");
    }
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