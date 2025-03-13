#include "honeybadger/communication/server/application_protocol_server/ApplicationProtocolServer.hh"
#include "honeybadger/communication/server/Logger.hh"
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <honeybadger/common/io_context/io_context/AsioIoContext.hh>
#include <honeybadger/common/io_context/io_context_manager/IOContextManager.hh>

namespace honeybadger::communication::server
{
ApplicationProtocolServer::ApplicationProtocolServer(std::shared_ptr<common::io_context::IOContextManager>
                                                         iOContextManager,
                                                     std::unique_ptr<network::interface::ServerSocket>
                                                         asyncServerSocket,
                                                     const common::types::Endpoint &endpoint,
                                                     std::unique_ptr<interface::ClientManager>
                                                         clientManager) :
    asyncServerSocket_(std::move(asyncServerSocket)),
    clientManager_(std::move(clientManager)), sctpEventManager_(), iOContextManager_(std::move(iOContextManager))
{
    asyncServerSocket_->bind(endpoint);
}

ApplicationProtocolServer::~ApplicationProtocolServer()
{
}

DISABLE_SWITCH_DEFAULT_WARNING_DUE_TO_BOOST_COROUTINES

common::coroutines::Task<void> ApplicationProtocolServer::acceptLoop()
{
    while(true)
    {
        if(!asyncServerSocket_)
        {
            ERROR_LOG("asyncServerSocket_ is null!");
            co_return;
        }
        auto connectedSocket = co_await asyncServerSocket_->accept();
        if(connectedSocket)
        {
            INFO_LOG("Accepted connection from ");
        }
    }
    co_return;
}

RESTORE_WARNINGS

void ApplicationProtocolServer::run()
{
    auto ioContext = iOContextManager_->getIOContext();
    if(!ioContext)
    {
        ERROR_LOG("ioContext is null!");
        return;
    }
    INFO_LOG("Starting server on1 ");
    auto asioTask = std::dynamic_pointer_cast<common::io_context::interface::AsioTask>(ioContext);
    if(!asioTask)
    {
        ERROR_LOG("Failed to get AsioTask from ioContext");
        return;
    }
    asioTask->spawnTask(std::bind(&ApplicationProtocolServer::acceptLoop, this));
    asyncServerSocket_->listen();

    INFO_LOG("Starting server on ");
    if(!ioContext)
    {
        ERROR_LOG("ioContext is null!");
        return;
    }
    ioContext->run();
}

void ApplicationProtocolServer::stop()
{
    if(not asyncServerSocket_->isClosed())
    {
        asyncServerSocket_->close();
    }
}
} // namespace honeybadger::communication::server