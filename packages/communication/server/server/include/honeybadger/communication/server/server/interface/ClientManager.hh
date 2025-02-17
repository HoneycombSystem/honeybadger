#pragma once
#include "honeybadger/communication/server/server/interface/Client.hh"
#include "honeybadger/communication/server/server/interface/ClientManagerMatcher.hh"
#include <memory>
#include <vector>

namespace honeybadger::communication::server::interface
{
class ClientManager
{
  public:
    virtual ~ClientManager() = default;
    virtual void addClient(std::shared_ptr<interface::Client>) = 0;
    virtual void removeClient(const common::types::Uuid &) = 0;
    virtual std::vector<std::shared_ptr<interface::Client>> filter(const interface::ClientManagerMatcher &) const = 0;
};
} // namespace honeybadger::communication::server::interface