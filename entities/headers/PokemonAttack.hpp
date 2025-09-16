#ifndef POKEMONATTACK_HPP
#define POKEMONATTACK_HPP
#include "PokemonParty.hpp"
#include "PokemonVector.hpp"
using namespace std;

class PokemonAttack : public PokemonVector {
public:

    PokemonAttack() ;

    void createSetFromParty(int number_of_pokemons = 1, int random_seed = 1234);

    void reintegrateAllToParty();

    void reintegrateDeadToParty();

    void createSetFromParty(const vector<int> & vector);

    void displayAllPokemons() override;

    vector<Pokemon>& getMyPokemons() ;

private:
    static const int MAX_POKEMON_PER_PARTY = 6;
    vector<Pokemon> attack_team;
};
#endif // POKEMONATTACK_HPP
