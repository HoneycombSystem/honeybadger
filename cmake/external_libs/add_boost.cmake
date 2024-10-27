function(add_boost TARGET)
  set(options)
  set(oneValueArgs TARGET)
  set(multiValueArgs REQUIRED_COMPONENTS LIBRARIES)

  cmake_parse_arguments(ARGS "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

  message(DEBUG "Adding Boost to ${TARGET}")
  message(DEBUG "Required components: ${ARGS_REQUIRED_COMPONENTS}")
  message(DEBUG "Libraries: ${ARGS_LIBRARIES}")

  set(BOOST_MIN_VERSION "1.86")
  message(DEBUG "Boost minimum version: ${BOOST_MIN_VERSION}")
  find_package(Boost ${BOOST_MIN_VERSION} QUIET REQUIRED COMPONENTS ${ARGS_REQUIRED_COMPONENTS})

  target_link_libraries(${TARGET} PRIVATE ${ARGS_LIBRARIES})
  target_include_directories(${TARGET} SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})
endfunction()
