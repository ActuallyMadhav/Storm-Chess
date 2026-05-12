cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    inc
    sprites
)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/board.cpp
)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    raylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
