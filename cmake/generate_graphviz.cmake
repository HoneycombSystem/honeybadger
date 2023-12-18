set(GRAPHVIZ_FILE_OUTPUT "${CMAKE_BINARY_DIR}/graphviz/${CMAKE_PROJECT_NAME}")
add_custom_target(
  graphviz
  COMMAND ${CMAKE_COMMAND} "--graphviz=${GRAPHVIZ_FILE_OUTPUT}.dot" .
  COMMAND dot -Tsvg ${GRAPHVIZ_FILE_OUTPUT}.dot -o ${GRAPHVIZ_FILE_OUTPUT}.svg
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")
