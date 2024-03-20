auto messageQueue = MessageQueueFactory().create();

auto endpoint = Endpoint(1232);
auto applicationProtocolBroker = ApplicationProtocolBrokerFactory(endpoint, messageQueue).create();

auto endpoint = Endpoint(3214);
auto controlProtocolBroker = ControlProtocolBrokerFactory(endpoint, messageQueue).create();

auto applicationProtocolSender = std::make_shared<ApplicationProtocolSender>(applicationProtocolBroker);

auto messagesDispatcher = MessageDispatcherFactory(messageQueue, applicationProtocolSender).create();

auto client = ControlProtocolClientFactory().create();
auto server = ControlProtocolServerFactory(client).create();

// cpp interface
class MessageQueue
{
  public:
    virtual ~MessageQueue() = default;

    virtual Message pop() = 0;
    virtual void push(const Message& message) = 0;
};

class MessageDispatcher
{
  public:
    virtual ~MessageDispatcher() = default;
    virtual void dispatch() = 0;
};

class Message
{
  public:
    virtual ~Message() = default;
    virtual const std::array<byte_t, 1024>& data() const = 0;
    virtual Identifier id() const = 0;
};

class ControlProtocolBrokerFactory
{
  public:
    virtual ~ControlProtocolBrokerFactory() = default;
    virtual std::unique_ptr<ControlProtocolBroker> create() = 0;
};

class ControlProtocolBroker
{
  public:
    virtual ~ControlProtocolBroker() = default;
    virtual void run() = 0;
    virtual void stop() = 0;
};

class Sender
{
  public:
    virtual ~Sender() = default;
    virtual void send(const Message& message) = 0;
};

class Server
{
  public:
    virtual ~Server() = default;
    virtual void connect() = 0;
    virtual void disconnect() = 0;
};

class Session
{
  public:
    virtual ~Session() = default;
    virtual Identifier id() const = 0;
    virtual void run() = 0;
    virtual void close() = 0;
};

class ApplicationProtocol : public Server
{
  public:
    virtual ~ApplicationProtocol() = default;
    virtual void connect() = 0;
    virtual void disconnect() = 0;
};

class WriteAbleSocket
{
  public:
    virtual ~WriteAbleSocket() = default;
    virtual void write(const std::array<byte_t, 1024>& data) = 0;
};

class ReadAbleSocket
{
  public:
    virtual ~ReadAbleSocket() = default;
    virtual std::array<byte_t, 1024> read() = 0;
};

class ServerSocket
{
  public:
    virtual ~Socket() = default;
    virtual void bind() = 0;
    virtual void listen() = 0;
    virtual void accept() = 0;
    virtual void close() = 0;
};
