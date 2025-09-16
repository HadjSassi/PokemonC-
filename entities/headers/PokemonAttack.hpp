#include "PokemonParty.hpp"
using namespace std;

class PokemonAttack : public PokemonVector {
public:

    PokemonAttack(PokemonParty &partie) ;

    void createSetFromParty(int number_of_pokemons = 1, int random_seed = 1234);

    void reintegrateAllToParty();

    void reintegrateDeadToParty();

    void createSetFromParty(const vector<int> & vector);

    void displayAllPokemons() override;

private:
    PokemonParty& party;
    static const int MAX_POKEMON_PER_PARTY = 6;
    vector<Pokemon> attack_team;
};
