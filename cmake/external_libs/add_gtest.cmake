function(add_gtest TARGET)
  message(DEBUG "Adding GTest to ${TARGET}")
  find_package(GTest QUIET REQUIRED)
  include(GoogleTest)
  target_link_libraries(
    ${TARGET}
    PRIVATE GTest::gtest
    PRIVATE GTest::gtest_main
    PRIVATE GTest::gmock
    PRIVATE GTest::gmock_main)
endfunction()
