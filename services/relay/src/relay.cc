#include "honeybadger/communication/sctp/broker/BrokerFactory.hh"

int main()
{
    honeybadger::communication::sctp::BrokerFactory brokerFactory;
    auto broker = brokerFactory.create(honeybadger::common::types::Endpoint("0.0.0.0", 4561));
    broker->start();
    return 0;
}