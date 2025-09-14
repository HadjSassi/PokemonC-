#include "PokemonVector.hpp"

class PokemonParty : public PokemonVector {
public:
    int getPokemonsCount() const;

    void addPokemonToParty(const Pokemon &pokemon);

    Pokemon extractPokemonFromPartyByIndex(int index);

    Pokemon extractPokemonFromPartyByName(string name);

    void displayAllPokemons() override;

private:
    vector<Pokemon> my_pokemons;
};
