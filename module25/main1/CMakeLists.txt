cmake_minimum_required(VERSION 3.16)

project("main1")

set(CMAKE_CXX_STANDARD 17)

add_executable(main1 src/main.cpp src/tools.cpp include/tools.h)

target_include_directories(main1 PUBLIC "${CMAKE_SOURCE_DIR}/include")
