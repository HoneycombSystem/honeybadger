#pragma once
#include "honeybadger/common/coroutines/task/Task.hh"
#include "honeybadger/communication/network/sctp/SctpEventManager.hh"
#include "honeybadger/communication/network/socket/interface/ServerSocket.hh"
#include "honeybadger/communication/server/server/interface/Client.hh"
#include "honeybadger/communication/server/server/interface/ClientManager.hh"
#include "honeybadger/communication/server/server/interface/Server.hh"
#include <honeybadger/common/io_context/io_context_manager/IOContextManager.hh>
#include <memory>

namespace honeybadger::communication::server
{
class ApplicationProtocolServer : public interface::Server
{
  public:
    ApplicationProtocolServer(std::shared_ptr<common::io_context::IOContextManager>,
                              std::unique_ptr<network::interface::ServerSocket>, const common::types::Endpoint &,
                              std::unique_ptr<interface::ClientManager>);
    ~ApplicationProtocolServer();
    void run() override;
    void stop() override;

  private:
    honeybadger::common::coroutines::Task<void> acceptLoop();
    std::unique_ptr<network::interface::ServerSocket> asyncServerSocket_;
    std::unique_ptr<interface::ClientManager> clientManager_;
    network::SctpEventManager sctpEventManager_;
    std::shared_ptr<common::io_context::IOContextManager> iOContextManager_;
};
} // namespace honeybadger::communication::server