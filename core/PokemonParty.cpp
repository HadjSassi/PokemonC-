#include "../headers/PokemonParty.hpp"

void PokemonParty::addPokemonToParty(const Pokemon pokemon) {
    my_pokemons.push_back(pokemon);
}

Pokemon* PokemonParty::extractPokemonFromPartyByIndex(int index) {
    if (index >= 0 && index < my_pokemons.size()) {
        Pokemon extracted = my_pokemons.at(index);
        my_pokemons.erase(my_pokemons.begin() + index);
        return &extracted;
    }
    return nullptr;
}

Pokemon* PokemonParty::extractPokemonFromPartyByName(string name) {
    for (size_t i = 0; i < my_pokemons.size(); ++i) {
        if (my_pokemons[i].getName() == name) {
            Pokemon extracted = my_pokemons.at(i);
            my_pokemons.erase(my_pokemons.begin() + i);
            return &extracted;
        }
    }
    return nullptr;
}