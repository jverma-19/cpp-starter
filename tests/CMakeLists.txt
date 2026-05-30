include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_adev test_adev.cpp)
target_link_libraries(test_adev PRIVATE cpp_starter GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_adev)
