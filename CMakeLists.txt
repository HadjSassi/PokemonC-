cmake_minimum_required(VERSION 3.28.3)
project(pokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(pokemon main.cpp
        entities/core/Pokemon.cpp
        entities/headers/Pokemon.hpp
        entities/core/PokemonVector.cpp
        entities/headers/PokemonVector.hpp
        entities/core/Pokedex.cpp
        entities/headers/Pokedex.hpp
        entities/core/PokemonParty.cpp
        entities/headers/PokemonParty.hpp
        entities/core/PokemonAttack.cpp
        entities/headers/PokemonAttack.hpp
        gui/BasePage.cpp
        gui/BasePage.hpp
        gui/HomePage/HomePage.cpp
        gui/HomePage/HomePage.hpp
        gui/WelcomePage/WelcomePage.cpp
        gui/WelcomePage/WelcomePage.hpp)

add_executable(pokemonUnitTest cunit/PokemonUnitTest.cpp
        entities/core/Pokemon.cpp
        entities/headers/Pokemon.hpp
        entities/core/PokemonVector.cpp
        entities/headers/PokemonVector.hpp
        entities/core/Pokedex.cpp
        entities/headers/Pokedex.hpp
        entities/core/PokemonParty.cpp
        entities/headers/PokemonParty.hpp
        entities/core/PokemonAttack.cpp
        entities/headers/PokemonAttack.hpp)


add_executable(pokedexUnitTest cunit/PokedexUnitTest.cpp
        entities/core/Pokemon.cpp
        entities/headers/Pokemon.hpp
        entities/core/PokemonVector.cpp
        entities/headers/PokemonVector.hpp
        entities/core/Pokedex.cpp
        entities/headers/Pokedex.hpp
        entities/core/PokemonParty.cpp
        entities/headers/PokemonParty.hpp
        entities/core/PokemonAttack.cpp
        entities/headers/PokemonAttack.hpp)

add_executable(pokemonPartyUnitTest cunit/PokemonPartyUnitTest.cpp
        entities/core/Pokemon.cpp
        entities/headers/Pokemon.hpp
        entities/core/PokemonVector.cpp
        entities/headers/PokemonVector.hpp
        entities/core/Pokedex.cpp
        entities/headers/Pokedex.hpp
        entities/core/PokemonParty.cpp
        entities/headers/PokemonParty.hpp
        entities/core/PokemonAttack.cpp
        entities/headers/PokemonAttack.hpp)

add_executable(pokemonAttackUnitTest cunit/PokemonAttackUnitTest.cpp
        entities/core/Pokemon.cpp
        entities/headers/Pokemon.hpp
        entities/core/PokemonVector.cpp
        entities/headers/PokemonVector.hpp
        entities/core/Pokedex.cpp
        entities/headers/Pokedex.hpp
        entities/core/PokemonParty.cpp
        entities/headers/PokemonParty.hpp
        entities/core/PokemonAttack.cpp
        entities/headers/PokemonAttack.hpp)

target_link_libraries(pokemon
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)