#include "PokemonVector.hpp"

class PokemonParty: public PokemonVector {

private:
    vector<Pokemon> my_pokemons;

public:
    void addPokemonToParty(const Pokemon pokemon);
    Pokemon* extractPokemonFromPartyByIndex(int index);
    Pokemon* extractPokemonFromPartyByName(string name);
};
