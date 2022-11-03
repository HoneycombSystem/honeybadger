option(ENABLE_CODE_COVERAGE "If ON code coverage can be measured." OFF)
if(ENABLE_CODE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    message(STATUS "Adding measuring code coverage for ${CMAKE_CXX_COMPILER_ID} compiler")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
    set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
  endif()
else()
  message(STATUS "Skipping code coverage")
endif()
