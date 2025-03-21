cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)

add_executable(OpenGLApp main.cpp)
target_link_libraries(OpenGLApp glfw glad)

