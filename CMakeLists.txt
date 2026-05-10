cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE__CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

include_directories(inc)

find_package(raylib REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(
    ${PROJECT_NAME} PRIVATE 
    raylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
