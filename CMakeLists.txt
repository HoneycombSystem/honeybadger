cmake_minimum_required(VERSION 3.22)
project(
  honeybadger
  VERSION 0.1.0
  LANGUAGES CXX)
message(STATUS "Project name: ${PROJECT_NAME}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

string(TIMESTAMP BUILD_TIME "%Y-%m-%d")
set(CURRENT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}-${BUILD_TIME}")
option(CMAKE_EXPORT_COMPILE_COMMANDS ON)
message(VERBOSE "CMAKE_EXPORT_COMPILE_COMMANDS: ${CMAKE_EXPORT_COMPILE_COMMANDS}")
option(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
message(VERBOSE "CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS: ${CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS}")
set(CMAKE_DEBUG_POSTFIX "-debug")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
  message(WARNING "Set default build type: ${CMAKE_BUILD_TYPE}")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
  set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Build version: ${CURRENT_VERSION}")

include(enable_code_coverage)
include(use_clang_tidy)
include(use_sanitizer)
include(enable_tests)

# include(enable_docs) include(enable_benchmarks) include(enable_examples)
