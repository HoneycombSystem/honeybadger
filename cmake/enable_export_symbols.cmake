cmake_dependent_option(
  ENABLE_EXPORTS
  "Enable exports"
  ON
  CMAKE_BUILD_TYPE
  MATCHES
  Debug
  OFF)
if(EXPORT_ALL_SYMBOLS)
  message(AUTHOR_WARNING "Exporting all symbols")
  set_property(TARGET compiler PROPERTY ENABLE_EXPORTS ON)
endif()
