cmake_minimum_required(VERSION 3.22)
project(
  honeybadger
  VERSION 0.1.0
  LANGUAGES CXX)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}")

execute_process(
  COMMAND git rev-parse --short HEAD
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  OUTPUT_VARIABLE GIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE)

string(TIMESTAMP BUILD_TIME "%Y-%m-%dT%H:%M:%SZ" UTC)
set(VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_DEBUG_POSTFIX "-debug")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
  message(WARNING "Set default build type: ${CMAKE_BUILD_TYPE}")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
  set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

message(
  STATUS
    "Build info:
  - Version: ${VERSION}
  - Git hash: ${GIT_HASH}
  - Build time: ${BUILD_TIME}
  - Build type: ${CMAKE_BUILD_TYPE}")

include(gcc_flags)
include(enable_code_coverage)
if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(ENABLE_CODE_COVERAGE ON)
endif()
include(use_sanitizer)
include(enable_tests)
include(logger/add_logger)

add_subdirectory(packages)
add_subdirectory(services)
