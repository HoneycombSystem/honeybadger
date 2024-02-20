#include "honeybadger/communication/broker/sctp/BrokerFactory.hh"

int main()
{
    honeybadger::communication::broker::BrokerFactory brokerFactory;
    auto broker = brokerFactory.create(honeybadger::common::types::Endpoint("127.0.0.1", 9898));
    broker->start();
    return 0;
}