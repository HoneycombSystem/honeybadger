#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServerFactory.hh"

int main()
{
    using namespace honeybadger::communication::server;
    auto applicationProtocolServer =
        ApplicationProtocolServerFactory(honeybadger::common::types::Endpoint("127.0.0.1", 9898)).create();
    applicationProtocolServer->start();
    return 0;
}