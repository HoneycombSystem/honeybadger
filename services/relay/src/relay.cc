#include "honeybadger/communication/protocols/application_protocol/ApplicationProtocolServiceFactory.hh"

int main()
{
    using namespace honeybadger::communication::protocols;
    auto applicationProtocolService = ApplicationProtocolServiceFactory().create();
    applicationProtocolService->start();
    return 0;
}