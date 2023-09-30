option(ENABLE_DOCS "Enable docs" ON)
if(ENABLE_DOCS)
  add_subdirectory(${CMAKE_SOURCE_DIR}/docs)
endif()
