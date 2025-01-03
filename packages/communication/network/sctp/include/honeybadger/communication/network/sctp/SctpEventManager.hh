#pragma once
#include "honeybadger/common/types/uuid/UUID.hh"
#include <functional>
#include <vector>

namespace honeybadger::communication::network
{
class SctpEventManager
{
  public:
    using Observer = std::function<void(const common::types::Uuid&)>;

    void subscribe(Observer observer)
    {
        observers_.emplace_back(std::move(observer));
    }

    void notify(const common::types::Uuid& id)
    {
        for(const auto& observer: observers_)
        {
            observer(id);
        }
    }

  private:
    std::vector<Observer> observers_{};
};
} // namespace honeybadger::communication::network