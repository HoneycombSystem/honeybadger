#include "honeybadger/common/io_context/io_context/AsioIOContext.hh"
#include "honeybadger/common/io_context/Logger.hh"
#include <boost/asio/co_spawn.hpp>
#include <boost/asio/detached.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/use_awaitable.hpp>

namespace honeybadger::common::io_context
{
AsioIOContext::AsioIOContext() : ioContext_(std::make_shared<boost::asio::io_context>())
{
}

AsioIOContext::AsioIOContext(AsioIOContext &&asioIOContext) : ioContext_{std::move(asioIOContext.ioContext_)}
{
}

AsioIOContext &AsioIOContext::operator=(AsioIOContext &&asioIOContext)
{
    ioContext_ = std::move(asioIOContext.ioContext_);
    return *this;
}

AsioIOContext::~AsioIOContext()
{
    ioContext_->stop();
}

void AsioIOContext::run()
{
    INFO_LOG("Starting io context");
    if(!ioContext_)
    {
        ERROR_LOG("ioContext_ is null!");
        return;
    }
    ioContext_->run();
}

void AsioIOContext::stop()
{
    ioContext_->stop();
}

void AsioIOContext::spawnTask(std::function<common::coroutines::Task<void>()> task)
{
    boost::asio::co_spawn(*ioContext_, task(), boost::asio::detached);
}

void *AsioIOContext::getNativeContextImpl()
{
    return ioContext_.get();
}
} // namespace honeybadger::common::io_context