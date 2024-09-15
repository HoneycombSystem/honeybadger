cmake_minimum_required(VERSION 3.22)
project(
  honeybadger
  VERSION 0.1.0
  LANGUAGES CXX)

# CMake module
include(CMakeDependentOption)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(BUILD_SHARED_LIBS OFF)
if(BUILD_SHARED_LIBS)
  message(STATUS "Building shared libraries, position independent code is enabled")
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  message(AUTHOR_WARNING "Building shared libraries is not recommended")
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_DEBUG_POSTFIX "-debug")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
  message(WARNING "Set default build type: ${CMAKE_BUILD_TYPE}")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
  set(CMAKE_BUILD_TYPE Release)
elseif(CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

include(print_info_about_project)

# Addtional targets
include(generate_graphviz)
include(logger/add_logger)

# Addtional options
include(enable_code_coverage)
include(use_sanitizer)
include(enable_tests)

# Addtional flags for compiler and linker
include(gcc_flags)
include(enable_export_symbols)

# These subdirectories must be included at the end
add_subdirectory(packages)
add_subdirectory(services)
