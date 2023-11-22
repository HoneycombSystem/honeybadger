#include "honeybadger/communication/sctp/broker/BrokerFactory.hh"

int main()
{
    honeybadger::communication::sctp::BrokerFactory brokerFactory;
    auto broker = brokerFactory.create(honeybadger::common::types::Endpoint("127.0.0.1", 9952));
    broker->start();
    return 0;
}