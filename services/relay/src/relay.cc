#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServiceFactory.hh"

int main()
{
    using namespace honeybadger::communication::protocols;
    const auto endpoint = honeybadger::common::types::Endpoint("127.0.0.1", 2137);
    auto applicationProtocolService = ApplicationProtocolServiceFactory(endpoint).create();
    applicationProtocolService->start();
    return 0;
}