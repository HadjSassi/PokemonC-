#include "../headers/PokemonParty.hpp"

PokemonParty* PokemonParty::instance = nullptr;

PokemonParty* PokemonParty::getInstance() {
    if (!instance) instance = new PokemonParty();
    return instance;
}

void PokemonParty::addPokemonToParty(const Pokemon &pokemon) {
    my_pokemons.push_back(pokemon);
}

int PokemonParty::getPokemonsCount() const {
    return my_pokemons.size();
}

Pokemon PokemonParty::extractPokemonFromPartyByIndex(int index) {
    if (index >= 0 && index < my_pokemons.size()) {
        Pokemon extracted = my_pokemons.at(index);
        my_pokemons.erase(my_pokemons.begin() + index);
        return extracted;
    }
    throw std::out_of_range("Index invalide");
}

Pokemon PokemonParty::extractPokemonFromPartyByName(string name) {
    for (size_t i = 0; i < my_pokemons.size(); ++i) {
        if (my_pokemons[i].getName() == name) {
            Pokemon extracted = my_pokemons.at(i);
            my_pokemons.erase(my_pokemons.begin() + i);
            return extracted;
        }
    }
    throw std::invalid_argument("Nom introuvable");
}

void PokemonParty::displayAllPokemons() {
    cout << "All Pokemons in the party " << endl;
    for (const Pokemon &pokemon: my_pokemons) {
        pokemon.displayInfo();
    }
    cout << "-----------------------" << endl;
}

bool PokemonParty::hasPokemonWithId(int index) {
    for (const Pokemon &pokemon: my_pokemons) {
        if (pokemon.getId() == index) {
            return true;
        }
    }
    return false;
}
