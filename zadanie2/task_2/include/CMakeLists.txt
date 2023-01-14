project(Task2)

add_library(Functions funct.cpp)
target_include_directories(Functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
