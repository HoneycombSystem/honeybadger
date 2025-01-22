#pragma once
#include "honeybadger/common/io_context/io_context_manager/interface/IOContextManager.hh"
#include "honeybadger/communication/protocols/protocols/interface/Context.hh"

namespace honeybadger::communication::protocols
{
class ApplicationProtocolContext : public interface::Context
{
  public:
    ApplicationProtocolContext(std::shared_ptr<common::io_context::interface::IOContextManager> ioContextManager);
    std::shared_ptr<common::io_context::interface::IOContextManager> getIOContextManager() override;

  private:
    std::shared_ptr<common::io_context::interface::IOContextManager> ioContextManager_;
};
} // namespace honeybadger::communication::protocols