#include <iostream>
#include <cassert>
#include "../headers/Pokedex.hpp"

using namespace std;

void testSingleton() {
    Pokedex* p1 = Pokedex::getInstance();
    Pokedex* p2 = Pokedex::getInstance();
    assert(p1 == p2);
}

void testDisplayAllPokemons() {
    Pokedex* pokedex = Pokedex::getInstance();
    pokedex->displayAllPokemons();
}

int main() {
    testSingleton();
    testDisplayAllPokemons();
    cout << "Tous les tests unitaires de Pokedex sont passes." << endl;
    return 0;
}