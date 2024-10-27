// #include "honeybadger/communication/network/sctp/SctpSocket.hh"
// #include "honeybadger/communication/network/socket/AddressFormatConverter.hh"
// #include <memory>
// #ifdef __linux__
//     #include <arpa/inet.h>
//     #include <linux/sctp.h>
//     #include <netinet/in.h>
// #elif _WIN32
//     #warning SCTP implementation for Windows is missing
// #else
//     #error SCTP implementation for this system is missing
// #endif
// #include "honeybadger/common/types/network/Endpoint.hh"
// #include "honeybadger/communication/network/Logger.hh"
// #include <boost/asio.hpp>

// namespace
// {
// template<typename ProtocolEndpoint>
// ProtocolEndpoint buildAsioEndpoint(const honeybadger::common::types::Endpoint &endpoint)
// {
//     auto protocolEndpointBuilder = [](auto &sockaddrIn)
//     {
//         return ProtocolEndpoint{
//             reinterpret_cast<sockaddr *>(&sockaddrIn),
//             sizeof(sockaddrIn),
//             IPPROTO_SCTP,
//         };
//     };
//     switch(endpoint.ipVersion)
//     {
//         using namespace honeybadger::communication::network;
//         using enum honeybadger::common::types::Endpoint::IpVersion;
//         case v4:
//         {
//             auto sockaddrIn = convertEndpointToSockaddrIn(endpoint);
//             return protocolEndpointBuilder(sockaddrIn);
//         }
//         case v6:
//         {
//             auto sockaddrIn6 = convertEndpointToSockaddrIn6(endpoint);
//             return protocolEndpointBuilder(sockaddrIn6);
//         }
//         case unknown:
//         default:
//             throw std::runtime_error("Unknown IP version");
//     }
// }
// } // namespace

// namespace honeybadger::communication::network
// {
// SctpSocket::~SctpSocket()
// {
//     closeConnectionOnBothSides();
// }

// SctpSocket::SctpSocket() : ioContext_(), acceptor_(ioContext_), socket_(ioContext_)
// {
//     selectSctpProtocolForAcceptor();
// }

// bool SctpSocket::bind(const common::types::Endpoint &endpoint)
// try
// {
//     DEBUG_LOG("SCTP socket bind to {}:{}", endpoint.ip, endpoint.port);
//     const auto streamProtocolEndpoint = buildAsioEndpoint<Protocol::endpoint>(endpoint);
//     acceptor_.bind(streamProtocolEndpoint);
//     return true;
// }
// catch(const boost::system::system_error &error)
// {
//     WARN_LOG("SCTP socket bind to {}:{} failed: {}", endpoint.ip, endpoint.port, error.what());
//     return false;
// }
// catch(const std::exception &error)
// {
//     WARN_LOG("SCTP socket bind to {}:{} failed: {}", endpoint.ip, endpoint.port, error.what());
//     return false;
// }
// catch(...)
// {
//     WARN_LOG("SCTP socket bind to {}:{} failed: unknown error", endpoint.ip, endpoint.port);
//     return false;
// }

// bool SctpSocket::listen()
// try
// {
//     const auto maxListenConnections = Protocol::socket::max_listen_connections;
//     DEBUG_LOG("SCTP socket listen with max connections: {}", maxListenConnections);
//     acceptor_.listen(maxListenConnections);
//     INFO_LOG("SCTP socket listen");
//     return true;
// }
// catch(const boost::system::system_error &error)
// {
//     WARN_LOG("SCTP socket listen failed: {}", error.what());
//     return false;
// }
// catch(const std::exception &error)
// {
//     WARN_LOG("SCTP socket listen failed: {}", error.what());
//     return false;
// }
// catch(...)
// {
//     WARN_LOG("SCTP socket listen failed: unknown error");
//     return false;
// }

// bool SctpSocket::asyncAccept()
// try
// {
//     // acceptor_.async_accept();
//     INFO_LOG("SCTP socket start accepting connections");
//         acceptor_.async_accept(socket_,
//                                [this](boost::system::error_code ec)
//         {
//             //accept handler which will be called when new connection is accepted, add connection to the list of
//             connections and start receiving data if(ec)
//             {
//                 WARN_LOG("SCTP socket accept failed: {}", ec.message());
//                 return;
//             }

//             DEBUG_LOG("SCTP socket accepted new connection");

//             // auto session = std::make_shared<Client>(std::move(socket_));
//             //show a Client implementation
//             // session->run();
//         });
//     return true;
// }
// catch(const boost::system::system_error &error)
// {
//     WARN_LOG("SCTP socket accept failed: {}", error.what());
//     return false;
// }
// catch(const std::exception &error)
// {
//     WARN_LOG("SCTP socket accept failed: {}", error.what());
//     return false;
// }
// catch(...)
// {
//     WARN_LOG("SCTP socket accept failed: unknown error");
//     return false;
// }

// // void Sctp::acceptHandler(boost::system::error_code ec, Protocol::socket)
// // {
// //     if(ec)
// //     {
// //         WARN_LOG("SCTP socket accept failed: {}", ec.message());
// //         return;
// //     }

// //     INFO_LOG("SCTP socket accepted new connection");
// //     // auto session = std::make_shared<Client>(std::move(socket));
// //     // session->run();
// //     // clients_.emplace_back(std::move(session));
// //     acceptHandler();
// // }

// // void Sctp::acceptHandler()
// // {
// //     acceptor_.async_accept(socket_,
// //                            [this](boost::system::error_code ec)
// //     {
// //         acceptHandler(ec, std::move(socket_));
// //     });
// // }

// bool SctpSocket::close()
// {
//     return closeConnectionOnBothSides();
// }

// void SctpSocket::selectSctpProtocolForAcceptor()
// {
//     acceptor_.open({AF_INET, IPPROTO_SCTP});
// }

// bool SctpSocket::closeConnectionOnBothSides()
// {
//     try
//     {
//         socket_.shutdown(Protocol::socket::shutdown_both);
//         acceptor_.close();
//         INFO_LOG("SCTP closed");
//     }
//     catch(const boost::system::system_error &error)
//     {
//         WARN_LOG("SCTP close failed: {}", error.what());
//         return false;
//     }
//     catch(const std::exception &error)
//     {
//         WARN_LOG("SCTP close failed: {}", error.what());
//         return false;
//     }
//     catch(...)
//     {
//         WARN_LOG("SCTP close failed: unknown error");
//         return false;
//     }
//     return true;
// }
// } // namespace honeybadger::communication::network