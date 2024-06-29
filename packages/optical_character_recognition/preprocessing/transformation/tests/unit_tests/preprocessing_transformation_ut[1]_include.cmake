if(EXISTS
   "/workspaces/honeybadger/packages/optical_character_recognition/preprocessing/transformation/tests/unit_tests/preprocessing_transformation_ut[1]_tests.cmake"
)
  include(
    "/workspaces/honeybadger/packages/optical_character_recognition/preprocessing/transformation/tests/unit_tests/preprocessing_transformation_ut[1]_tests.cmake"
  )
else()
  add_test(preprocessing_transformation_ut_NOT_BUILT preprocessing_transformation_ut_NOT_BUILT)
endif()
