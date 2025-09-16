#include "../headers/PokemonAttack.hpp"

#include <stdexcept>

PokemonAttack::PokemonAttack() : PokemonVector() {
    attack_team.clear();
}

void PokemonAttack::createSetFromParty(int number_of_pokemons, int random_seed) {
    if (number_of_pokemons < 1 || number_of_pokemons > MAX_POKEMON_PER_PARTY) {
        throw invalid_argument("Number of pokemons must be between 1 and " + to_string(MAX_POKEMON_PER_PARTY));
    }
    if (number_of_pokemons > getPokemonsCount()) {
        throw invalid_argument("Not enough pokemons in party to create the attack set");
    }

    attack_team.clear();
    srand(random_seed);
    vector<int> selected_indices;
    while (attack_team.size() < number_of_pokemons) {
        int index = rand() % getPokemonsCount();
        attack_team.push_back(PokemonParty::getInstance().extractPokemonFromPartyByIndex(index));
    }
}

void PokemonAttack::reintegrateAllToParty() {
    for (Pokemon &pokemon: attack_team) {
        pokemon.heal(pokemon.getMaxLife());
        PokemonParty::getInstance().addPokemonToParty(pokemon);
    }
    attack_team.clear();
}

void PokemonAttack::reintegrateDeadToParty() {
    for (Pokemon pokemon: attack_team) {
        if (pokemon.getHitPoint() <= 0) {
            pokemon.heal(pokemon.getMaxLife());
            PokemonParty::getInstance().addPokemonToParty(pokemon);
        }
    }
}

void PokemonAttack::createSetFromParty(const vector<int> &vector) {
    for (int index : vector)
        attack_team.push_back(PokemonParty::getInstance().extractPokemonFromPartyByIndex(index));
}


void PokemonAttack::displayAllPokemons() {
    cout << "All Pokemons in the attack team " << endl;
    for (const Pokemon &pokemon: attack_team) {
        pokemon.displayInfo();
    }
    cout << "-----------------------" << endl;
}

vector<Pokemon>& PokemonAttack::getMyPokemons()  {
    return attack_team;
}
