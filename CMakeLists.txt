cmake_minimum_required(VERSION 3.9)
project(inheritance_exercise)

set(CMAKE_CXX_STANDARD 14)

add_library(catch test/catch_main.cpp)

add_executable(test_task1
    test/catch_main.cpp
    test/test_task1.cpp)
target_link_libraries(test_task1 catch)

add_executable(test_task2
    test/catch_main.cpp
    test/test_task2.cpp)
target_link_libraries(test_task2 catch)

add_executable(test_task3
    test/catch_main.cpp
    test/test_task3.cpp)
target_link_libraries(test_task3 catch)