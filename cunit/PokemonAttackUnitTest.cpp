#include <iostream>
#include <cassert>
#include "../entities/headers/PokemonAttack.hpp"

using namespace std;

void testCreateSetFromParty() {
    PokemonAttack attackParty;
    for (int i = 0; i < 6; ++i) {
        attackParty.addPokemonToParty(Pokemon(i, "Poke" + to_string(i), 100, 50, 30, 1, 100));
    }
    assert(attackParty.getPokemonsCount() == 6);

    attackParty.createSetFromParty(3, 42);
    assert(attackParty.getPokemonsCount() == 3);

    try {
        attackParty.createSetFromParty(10);
        assert(false);
    } catch (const invalid_argument &) {
    }
}

void testReintegrateAllToParty() {
    PokemonAttack attackParty;
    for (int i = 0; i < 4; ++i) {
        attackParty.addPokemonToParty(Pokemon(i, "Poke" + to_string(i), 100, 50, 30, 1, 100));
    }
    attackParty.createSetFromParty(2, 1);
    assert(attackParty.getPokemonsCount() == 2);
    attackParty.reintegrateAllToParty();
    assert(attackParty.getPokemonsCount() == 4);
}

void testReintegrateDeadToParty() {
    PokemonAttack attackParty;
    for (int i = 0; i < 3; ++i) {
        attackParty.addPokemonToParty(Pokemon(i, "Poke" + to_string(i), 100, 50, 30, 1, 100));
    }
    attackParty.createSetFromParty(2, 2);

    attackParty.reintegrateDeadToParty();
    assert(attackParty.getPokemonsCount() == 1 || attackParty.getPokemonsCount() == 2);
}

int main() {
    testCreateSetFromParty();
    testReintegrateAllToParty();
    testReintegrateDeadToParty();
    cout << "Tous les tests unitaires de PokemonAttack sont passes." << endl;
    return 0;
}
