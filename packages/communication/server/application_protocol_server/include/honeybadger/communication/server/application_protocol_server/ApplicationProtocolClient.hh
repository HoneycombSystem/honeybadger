#pragma once
#include "honeybadger/communication/server/server/interface/Client.hh"

namespace honeybadger::communication::server
{
class ApplicationProtocolClient : public interface::Client
{
  public:
    ApplicationProtocolClient();
    ~ApplicationProtocolClient();
    void run() override;
    bool isRunning() const override;
    common::types::Uuid getId() const override;
};
} // namespace honeybadger::communication::server