#include "PokemonParty.hpp"
using namespace std;

class PokemonAttack : public PokemonParty {
public:
    void createSetFromParty(int number_of_pokemons = 1, int random_seed = 1234);

    void reintegrateAllToParty();

    void reintegrateDeadToParty();

private:
    static const int MAX_POKEMON_PER_PARTY = 6;
    vector<Pokemon> attack_team;
};
