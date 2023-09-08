cmake_minimum_required(VERSION 3.24)
project(heat_exchange_glfw)
set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

include_directories(glad/include)
add_executable(heat_exchange_glfw main.cpp glad/src/glad.c App.cpp App.h Enviroment.cpp Environment.h Seeders.cpp Seeders.h Arrays.cpp Arrays.h)

target_link_libraries(heat_exchange_glfw kernel32 user32 gdi32)
target_link_libraries(heat_exchange_glfw OpenGL::GL)
target_link_libraries(heat_exchange_glfw glfw)

