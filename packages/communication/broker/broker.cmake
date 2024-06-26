project(
  ${PACKAGE_NAME}_${MODULE_NAME}
  VERSION 0.1.0
  LANGUAGES CXX)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${CMAKE_PROJECT_NAME}::${PACKAGE_NAME}::${MODULE_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
                      INTERFACE ${CMAKE_PROJECT_NAME}::${PACKAGE_NAME}::${MODULE_NAME}::broker_interface)
target_link_libraries(${PROJECT_NAME}
                      INTERFACE ${CMAKE_PROJECT_NAME}::${PACKAGE_NAME}::${MODULE_NAME}::application_protocol_broker)
