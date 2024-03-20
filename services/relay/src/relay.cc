#include "honeybadger/communication/broker/application_protocol_broker/ApplicationProtocolBrokerFactory.hh"

int main()
{
    using namespace honeybadger::communication::broker;
    auto applicationProtocolBroker =
        ApplicationProtocolBrokerFactory(honeybadger::common::types::Endpoint("127.0.0.1", 9898)).create();
    applicationProtocolBroker->run();
    return 0;
}