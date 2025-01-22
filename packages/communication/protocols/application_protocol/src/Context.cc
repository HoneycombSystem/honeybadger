#include "honeybadger/communication/protocols/application_protocol/Context.hh"

namespace honeybadger::communication::protocols
{
ApplicationProtocolContext::ApplicationProtocolContext(
    std::shared_ptr<common::io_context::interface::IOContextManager> ioContextManager) :
    ioContextManager_(ioContextManager)
{
}

std::shared_ptr<common::io_context::interface::IOContextManager> ApplicationProtocolContext::getIOContextManager()
{
    return ioContextManager_;
}
} // namespace honeybadger::communication::protocols
