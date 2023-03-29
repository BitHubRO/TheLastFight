cmake_minimum_required(VERSION 3.24)
project(project C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c char_creation.c char_creation.h Fight.c Fight.h Monster.c monster.h special_events.c special_events.h start_end.c start_end.h Custom_structures.h)

# link the libraries
target_link_libraries(project m)

file(GLOB Files_to_copy "ASCII/*")
file(COPY ${Files_to_copy} DESTINATION ${CMAKE_BINARY_DIR})