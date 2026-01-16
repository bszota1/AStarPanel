cmake_minimum_required(VERSION 4.1)
project(AStarPanel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(SFML 3 COMPONENTS Graphics Window System REQUIRED)

add_executable(AStarPanel src/main.cpp
        include/Node.h
        include/Grid.h
        src/Grid.cpp
)

target_include_directories(AStarPanel PRIVATE include .)

target_link_libraries(AStarPanel PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)


