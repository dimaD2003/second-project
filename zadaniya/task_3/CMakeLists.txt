cmake_minimum_required(VERSION 3.15)
project(Task3)

add_executable(main main.cpp)

target_link_libraries(main Functions)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(googletest)
add_executable(tests tests.cpp)
target_link_libraries(tests gtest gtest_main)
target_link_libraries(tests Functions)

