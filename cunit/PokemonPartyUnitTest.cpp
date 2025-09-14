#include <iostream>
#include <cassert>
#include "../entities/headers/PokemonParty.hpp"

using namespace std;

void testAjoutEtComptage() {
    PokemonParty party;
    assert(party.getPokemonsCount() == 0);

    Pokemon p1(1, "Pikachu", 100, 50, 30, 1, 100);
    Pokemon p2(2, "Bulbasaur", 90, 40, 35, 1, 90);

    party.addPokemonToParty(p1);
    party.addPokemonToParty(p2);

    assert(party.getPokemonsCount() == 2);
}

void testExtractionParIndex() {
    PokemonParty party;
    Pokemon p1(1, "Pikachu", 100, 50, 30, 1, 100);
    Pokemon p2(2, "Bulbasaur", 90, 40, 35, 1, 90);

    party.addPokemonToParty(p1);
    party.addPokemonToParty(p2);

    Pokemon extrait = party.extractPokemonFromPartyByIndex(0);
    assert(extrait.getName() == "Pikachu");
    assert(party.getPokemonsCount() == 1);

    try {
        party.extractPokemonFromPartyByIndex(10);
        assert(false);
    } catch (const std::out_of_range &) {
    }
}

void testExtractionParNom() {
    PokemonParty party;
    Pokemon p1(1, "Pikachu", 100, 50, 30, 1, 100);
    Pokemon p2(2, "Bulbasaur", 90, 40, 35, 1, 90);

    party.addPokemonToParty(p1);
    party.addPokemonToParty(p2);

    Pokemon extrait = party.extractPokemonFromPartyByName("Bulbasaur");
    assert(extrait.getId() == 2);
    assert(party.getPokemonsCount() == 1);

    try {
        party.extractPokemonFromPartyByName("Inexistant");
        assert(false);
    } catch (const std::invalid_argument &) {
    }
}

void testAffichage() {
    PokemonParty party;
    Pokemon p1(1, "Pikachu", 100, 50, 30, 1, 100);
    party.addPokemonToParty(p1);
    party.addPokemonToParty(p1);
    party.addPokemonToParty(p1);

    party.displayAllPokemons();
}

int main() {
    testAjoutEtComptage();
    testExtractionParIndex();
    testExtractionParNom();
    testAffichage();
    cout << "Tous les tests unitaires de PokemonParty sont passes." << endl;
    return 0;
}
