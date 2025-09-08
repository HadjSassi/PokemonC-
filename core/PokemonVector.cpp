#include <iostream>
#include "../headers/PokemonVector.hpp"


void PokemonVector::displayAllPokemons()  {
    for (Pokemon &pokemon : pokemons) {
        pokemon.displayInfo();
        cout << "------------------------" << endl;
    }
}