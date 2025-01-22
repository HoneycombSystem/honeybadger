#include "honeybadger/common/io_context/io_context/interface/AsioTask.hh"
#include "honeybadger/common/io_context/io_context/interface/IOContext.hh"
#include <boost/asio/io_context.hpp>

namespace honeybadger::common::io_context
{
class AsioIOContext : public interface::IOContext, public interface::AsioTask
{
  public:
    AsioIOContext();
    AsioIOContext(const AsioIOContext &) = delete;
    AsioIOContext(AsioIOContext &&);
    AsioIOContext &operator=(const AsioIOContext &) = delete;
    AsioIOContext &operator=(AsioIOContext &&);
    ~AsioIOContext() override;

    void run() override;
    void stop() override;
    void spawnTask(std::function<common::coroutines::Task<void>()>) override;

  protected:
    void *getNativeContextImpl() override;

  private:
    std::shared_ptr<boost::asio::io_context> ioContext_;
};
} // namespace honeybadger::common::io_context