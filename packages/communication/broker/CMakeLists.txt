set(COMPONENT_NAME "broker")

add_subdirectory(broker)
add_subdirectory(application_protocol_broker)

include(broker.cmake)
