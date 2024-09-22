# Runable services

## Start vs Run method
### Start
- start() method is when we want to start the service in new thread and inside the service we can use the run() method to do the work.

### Run
- run() method is when we want to run the service in the same thread.

## Example
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
