cmake_minimum_required(VERSION 3.28.3)
project(pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(pokemon main.cpp
        core/Pokemon.cpp
        headers/Pokemon.hpp)

target_link_libraries(pokemon
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)