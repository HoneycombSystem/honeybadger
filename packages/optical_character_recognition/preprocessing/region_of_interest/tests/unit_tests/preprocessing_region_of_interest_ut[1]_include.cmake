if(EXISTS
   "/workspaces/honeybadger/packages/optical_character_recognition/preprocessing/region_of_interest/tests/unit_tests/preprocessing_region_of_interest_ut[1]_tests.cmake"
)
  include(
    "/workspaces/honeybadger/packages/optical_character_recognition/preprocessing/region_of_interest/tests/unit_tests/preprocessing_region_of_interest_ut[1]_tests.cmake"
  )
else()
  add_test(preprocessing_region_of_interest_ut_NOT_BUILT preprocessing_region_of_interest_ut_NOT_BUILT)
endif()
