cmake_minimum_required(VERSION 3.15)

project(returner)

add_executable(returner main.cpp)

target_include_directories(returner PRIVATE .)

target_compile_features(returner PRIVATE cxx_std_20)

target_compile_options(returner PRIVATE -Wall -Wextra -Werror -pedantic-errors)
