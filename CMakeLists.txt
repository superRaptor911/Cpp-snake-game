cmake_minimum_required(VERSION 3.7)

project(R2D)


set(CMAKE_CXX_FLAGS "-Wall -std=c++1z -lstdc++fs")
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# External deps
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/SFML-2.5.1)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/freetype)
# Testing dir
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)


#Library
add_library(Engine src/utility/Strings.cpp src/utility/File.cpp)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/SFML-2.5.1/include/ ${CMAKE_CURRENT_SOURCE_DIR}/include/)

message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")

#-lm
#target_compile_options(RG PUBLIC)
target_link_libraries(Engine sfml-window sfml-graphics sfml-audio)
#OpenGL::GL

add_executable(Main main.cpp)
target_compile_options(Main PUBLIC)
target_link_libraries(Main Engine)
