cmake_minimum_required(VERSION 3.5)
PROJECT(test-cpptest)

find_package(CppUTest REQUIRED)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CppUTest_DIR})
include(CppUTestConfig)

ADD_LIBRARY(test-lib src/lib.c)

target_include_directories(test-lib PUBLIC api)

ADD_EXECUTABLE(test-cpputest test/main.cpp test/test.cpp)
target_include_directories(test-cpputest PRIVATE ${CppUTest_INCLUDE_DIRS} api)
target_link_libraries(test-cpputest PRIVATE ${CppUTest_LIBRARIES} test-lib)

enable_testing()
add_test(NAME base_test COMMAND test-cpputest)
add_test(NAME base_test_verbose COMMAND test-cpputest -v )
add_test(NAME base_test_random COMMAND test-cpputest -p )