cmake_minimum_required(VERSION 3.10)
project(btWallet)

set(CMAKE_CXX_STANDARD 11)

add_executable(btWallet main.cpp)

target_link_libraries(btWallet -lboost_program_options)