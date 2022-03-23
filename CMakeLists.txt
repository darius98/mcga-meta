cmake_minimum_required(VERSION 3.18)
project(MCGA_meta)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

option(MCGA_meta_tests "Build MCGA Meta tests" OFF)

add_library(mcga_meta INTERFACE)
target_include_directories(mcga_meta INTERFACE include)

install(DIRECTORY include DESTINATION .)

if (MCGA_meta_tests)
    add_executable(mcga_meta_test
            tests/manual_lifetime_test.cpp)
    target_link_libraries(mcga_meta_test mcga_test mcga_meta)
endif ()
