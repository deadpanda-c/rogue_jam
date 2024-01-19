cmake_minimum_required(VERSION 3.22)
project(rogue_jam)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES "src/*.cpp")

include_directories(include)

add_executable(rogue ${SOURCES})
target_link_libraries(rogue sfml-graphics sfml-window sfml-system sfml-audio)
