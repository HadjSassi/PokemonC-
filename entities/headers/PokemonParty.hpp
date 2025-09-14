#include "PokemonVector.hpp"

class PokemonParty : public PokemonVector {
public:
    static PokemonParty *getInstance();

    int getPokemonsCount() const;

    void addPokemonToParty(const Pokemon &pokemon);

    Pokemon extractPokemonFromPartyByIndex(int index);

    Pokemon extractPokemonFromPartyByName(string name);

    void displayAllPokemons() override;

    bool hasPokemonWithId(int index);

private:
    static PokemonParty *instance;

    PokemonParty() = default;

    vector<Pokemon> my_pokemons;
};
