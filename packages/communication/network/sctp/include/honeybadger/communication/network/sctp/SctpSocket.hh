#pragma once
#include "honeybadger/communication/network/socket/interface/CloseableSocket.hh"
#include "honeybadger/communication/network/socket/interface/ConnectedSocket.hh"
#include "honeybadger/communication/network/socket/interface/ReceiverSocket.hh"
#include "honeybadger/communication/network/socket/interface/SenderSocket.hh"
#include "honeybadger/communication/network/socket/interface/ServerSocket.hh"
#include <boost/asio.hpp>

namespace honeybadger::common::types
{
class Endpoint;
} // namespace honeybadger::common::types

namespace honeybadger::communication::network
{
class SctpSocket : std::enable_shared_from_this<SctpSocket>
{
  public:
    SctpSocket(const SctpSocket &) = delete;
    SctpSocket(SctpSocket &&) = delete;
    SctpSocket &operator=(const SctpSocket &) = delete;
    SctpSocket &operator=(SctpSocket &&) = delete;

    SctpSocket();
    ~SctpSocket();

    bool bind(const common::types::Endpoint &endpoint);
    bool listen();
    common::coroutines::Task<std::unique_ptr<interface::ConnectedSocket>> accept();
    void close();
    bool isClosed() const;
    common::coroutines::Task<void> send(const common::types::Payload &payload);
    common::coroutines::Task<common::types::Payload> receive();


    common::coroutines::Task<void> acceptloop();
void startloop();
  //getExecutor
DISABLE_SWITCH_DEFAULT_WARNING_DUE_TO_BOOST_COROUTINES

  common::coroutines::Task<void> sync()
  {
    co_await boost::asio::post(ioContext_->get_executor(), boost::asio::use_awaitable);
  }
RESTORE_WARNINGS
  private:
    using Protocol = boost::asio::generic::stream_protocol;

    void selectSctpProtocolForAcceptor();
    bool closeConnectionOnBothSides();
    std::shared_ptr<SctpSocket> createConnectedSocketFromThis(std::shared_ptr<Protocol::socket>);

    std::shared_ptr<boost::asio::io_context> ioContext_;
    boost::asio::basic_socket_acceptor<Protocol> acceptor_;
    std::shared_ptr<Protocol::socket> socket_;
    boost::asio::executor_work_guard<boost::asio::io_context::executor_type> work_guard_;
};
} // namespace honeybadger::communication::network