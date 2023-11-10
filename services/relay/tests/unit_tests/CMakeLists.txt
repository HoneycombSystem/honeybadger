project(${COMPONENT_NAME}_${MODULE_NAME}_ut LANGUAGES CXX)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE)
add_executable(${PROJECT_NAME} ${SOURCE})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
             LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
             RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
             CXX_STANDARD 20
             CXX_EXTENSIONS OFF
             CXX_STANDARD_REQUIRED ON)

find_package(GTest QUIET REQUIRED)
include(GoogleTest)

target_link_libraries(${PROJECT_NAME} PRIVATE ${COMPONENT_NAME}_${MODULE_NAME})
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE GTest::gtest
  PRIVATE GTest::gtest_main
  PRIVATE GTest::gmock
  PRIVATE GTest::gmock_main)

gtest_discover_tests(${PROJECT_NAME} WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
