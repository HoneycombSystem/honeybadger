#include "honeybadger/communication/server/server/interface/Client.hh"
#include "honeybadger/communication/network/socket/interface/ConnectedSocket.hh"
#include "honeybadger/common/types/uuid/Uuid.hh"

namespace honeybadger::communication::server
{
class ApplicationProtocolClient : public interface::Client
{
    public:
    ApplicationProtocolClient(std::unique_ptr<network::interface::ConnectedSocket> connectedSocket);
    ~ApplicationProtocolClient() override;

    void run() override;
    bool isRunning() const override;
    common::types::Uuid getId() const override;

    private:
    std::unique_ptr<network::interface::ConnectedSocket> connectedSocket_;
    bool isRunning_;
    common::types::Uuid id_;
};
}