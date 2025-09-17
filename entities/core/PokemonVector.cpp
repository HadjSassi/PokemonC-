#include <iostream>
#include "../headers/PokemonVector.hpp"
#include "../../config.hpp"

void PokemonVector::addPokemon(const Pokemon &pokemon) {
    pokemons.push_back(pokemon);
}

const Pokemon &PokemonVector::getPokemonAt(int index) const {
    return pokemons.at(index);
}

int PokemonVector::getPokemonsCount() const {
    return pokemons.size();
}

const vector<Pokemon> &PokemonVector::getPokemons() const {
    return pokemons;
}

Pokemon *PokemonVector::getPokemonByIndex(int index) {
    if (index >= 0 && index < getPokemonsCount()) {
        return new Pokemon(getPokemonAt(index));
    }
    throw out_of_range(INDEX_OUT_OF_RANGE + std::to_string(index));
}

Pokemon *PokemonVector::getPokemonByName(string name) {
    for (const Pokemon &pokemon: getPokemons()) {
        if (pokemon.getName() == name) {
            return new Pokemon(pokemon);
        }
    }
    throw invalid_argument(POKEMON_NOT_FOUND+name);
}
