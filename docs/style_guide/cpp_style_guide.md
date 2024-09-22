# C++ style guide
This document is intended to provide a set of guidelines for writing C++ code for the Honeybadger project. The goal is to ensure that the codebase is consistent and easy to read and understand. This will make it easier for developers to work on the project and for new developers to get up to speed quickly.

## Table of Contents
- [C++ style guide](#c-style-guide)
  - [Table of Contents](#table-of-contents)
  - [Runable services](#runable-services)
    - [Start vs Run method](#start-vs-run-method)
      - [Start](#start)
      - [Run](#run)
      - [Example](#example)
  - [Namespaces](#namespaces)
    - [Nesting level](#nesting-level)
    - [Example](#example-1)

## Runable services
### Start vs Run method
#### Start
- start() method is when we want to start the service in new thread and inside the service we can use the run() method to do the work.
- used in high level services
- used in services that need to be started in a new thread

#### Run
- run() method is when we want to run the service in the same thread.
- used in under high level services
- used in services that need to be run in the same thread

#### Example
```cpp
struct AppServer : public Server
{
    void run() override
    {
        while (true)
        {
            // do work
        }
    }
}

struct AppService : public Service
{
    AppServer server;
    void start() override
    {
        std::thread(&AppServer::run, &server).detach();
    }
}

int main()
{
    AppService service;
    service.start();
}
```

## Namespaces
### Nesting level
- prefer nested namespace definition
- honeybadger::module_name::component_name
### Example
```cpp
namespace honeybadger::communication::network
{
    class Socket;
}
namespace honeybadger::communication::protocol
{
    class Http;
}
```
or if we have a multiple classes in the same module but different components
```cpp
namespace honeybadger::communication
{
    namespace network
    {
        class Socket;
    }
    namespace protocol
    {
        class Http;
    }
}
```
