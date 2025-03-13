#include "honeybadger/common/io_context/io_context_manager/IOContextManager.hh"
#include "honeybadger/common/io_context/io_context/AsioIOContext.hh"
#include "honeybadger/common/io_context/Logger.hh"
#include <memory>

namespace honeybadger::common::io_context
{
std::shared_ptr<interface::IOContext> IOContextManager::getIOContext()
{
    if(!ioContext_)
    {
        ioContext_ = std::shared_ptr<interface::IOContext>(new AsioIOContext);
        INFO_LOG("NEW io context");
    }
    return ioContext_;
}
} // namespace honeybadger::common::io_context