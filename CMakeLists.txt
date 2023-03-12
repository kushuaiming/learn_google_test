cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        03597a01ee50ed33e9dfd640b249b4be3799d395
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  math_test
  math_test.cc
)
target_link_libraries(
  math_test
  GTest::gtest_main
)
target_include_directories(math_test
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/
)

include(GoogleTest)
gtest_discover_tests(math_test)