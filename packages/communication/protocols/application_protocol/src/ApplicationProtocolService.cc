#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolService.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolService::ApplicationProtocolService(std::unique_ptr<interface::Protocol> applicationProtocol) :
    applicationProtocol_(std::move(applicationProtocol))
{
}

void ApplicationProtocolService::start()
{
    applicationProtocol_->run();
}
} // namespace honeybadger::communication::protocols