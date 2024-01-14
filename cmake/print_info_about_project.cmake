execute_process(
  COMMAND git rev-parse --short HEAD
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  OUTPUT_VARIABLE GIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE)

string(TIMESTAMP BUILD_TIME "%Y-%m-%dT%H:%M:%SZ" UTC)
set(VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

message(
  STATUS
    "Build info:
  - Project:
    - Name: ${CMAKE_PROJECT_NAME}
    - Version: ${VERSION}
  - Git hash: ${GIT_HASH}
  - Build time: ${BUILD_TIME}
  - Build type: ${CMAKE_BUILD_TYPE}")

message(
  TRACE
  "Build detail:
  - System:
    - OS: ${CMAKE_SYSTEM_NAME}
    - Version: ${CMAKE_SYSTEM_VERSION}
    - Architecture: ${CMAKE_SYSTEM_PROCESSOR}
  - Toolchain:
    - CMake: ${CMAKE_VERSION}
    - Compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
