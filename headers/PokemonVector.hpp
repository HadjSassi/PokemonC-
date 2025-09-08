#include <vector>
#include "Pokemon.hpp"


using namespace std;
using std::vector;

class PokemonVector {

private:
    vector<Pokemon> pokemons;

public:
    virtual Pokemon getPokemonByIndex(int index)  = 0;
    virtual Pokemon getPokemonByName(string name)  = 0;
    void displayAllPokemons() ;
};