# Services

The service is a stand-alone application that interworks with other services. It is developed on the principles of building microservices. Each service can be deployed independently of the others.


- [Services](#services)
  - [Services List](#services-list)
    - [Application Service](#application-service)
    - [Control Service](#control-service)
    - [DataHub Service](#datahub-service)
    - [Telemetry Service](#telemetry-service)
  - [Application Service](#application-service-1)
  - [Control Service](#control-service-1)
  - [DataHub Service](#datahub-service-1)
  - [Telemetry Service](#telemetry-service-1)

## Services List
### [Application Service](../services//relay/docs/README.md)
### [Control Service](control-service.md)
### [DataHub Service](datahub-service.md)
### [Telemetry Service](telemetry-service.md)

## Application Service

Application service is responsible for communicating on business logic. Like communicating with the Spring application, which is responsible for exposing the API.


## Control Service

Control service is responsible for communications with Queenbee. At the moment, Control Service is responsible for the real-time configuration of Honeybadger application.

## DataHub Service

DataHub service is responsible for communicating with the Honeycomb application. It is responsible for sending requests and receiving responses on data that is stored in the database.

## Telemetry Service

Telemetry Service is responsible for collecting telemetry data from the Honeybadger application. And sending them to the Drone service.