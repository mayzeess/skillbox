cmake_minimum_required(VERSION 3.10.0)
project(main1 VERSION 0.1.0 LANGUAGES C CXX)

set(JSON_Install OFF CACHE INTERNAL "")
add_subdirectory("nlohmann json")


add_executable(main1 main.cpp)

target_link_libraries(main1 PRIVATE nlohmann_json::nlohmann_json)