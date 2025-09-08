cmake_minimum_required(VERSION 3.28.3)
project(pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(pokemon main.cpp
        core/Pokemon.cpp
        headers/Pokemon.hpp
        core/PokemonVector.cpp
        headers/PokemonVector.hpp
        core/Pokedex.cpp
        headers/Pokedex.hpp
        core/PokemonParty.cpp
        headers/PokemonParty.hpp
        core/PokemonAttack.cpp
        headers/PokemonAttack.hpp)

target_link_libraries(pokemon
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)