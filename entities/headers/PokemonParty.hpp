#ifndef POKEMONPARTY_HPP
#define POKEMONPARTY_HPP
#include "PokemonAttack.hpp"
class PokemonAttack;
#include "PokemonVector.hpp"


class PokemonParty : public PokemonVector {
public:
    static PokemonParty &getInstance();

    int getPokemonsCount() const;

    void addPokemonToParty(const Pokemon &pokemon);

    Pokemon extractPokemonFromPartyByIndex(int index);

    Pokemon extractPokemonFromPartyByName(string name);

    void displayAllPokemons() override;

    bool hasPokemonWithId(int index);

    const vector<Pokemon> &getPokemons() const;

    PokemonAttack *attack;

private:
    PokemonParty();

    PokemonParty(const PokemonParty &) = delete;

    vector<Pokemon> my_pokemons;
};
#endif // POKEMONPARTY_HPP
