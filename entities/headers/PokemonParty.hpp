#ifndef POKEMONPARTY_HPP
#define POKEMONPARTY_HPP
#include "PokemonVector.hpp"

class PokemonParty : public PokemonVector {
public:

    PokemonParty();

    int getPokemonsCount() const;

    void addPokemonToParty(const Pokemon &pokemon);

    Pokemon extractPokemonFromPartyByIndex(int index);

    Pokemon extractPokemonFromPartyByName(string name);

    void displayAllPokemons() override;

    bool hasPokemonWithId(int index);

    const vector<Pokemon> &getPokemons() const;

private:
    vector<Pokemon> my_pokemons;
};
#endif // POKEMONPARTY_HPP
