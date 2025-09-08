#include <vector>
#include "Pokemon.hpp"


using namespace std;
using std::vector;

class PokemonVector {

private:
    vector<Pokemon> pokemons;
    ~PokemonVector();

protected:
    void addPokemon(const Pokemon& pokemon) {
        pokemons.push_back(pokemon);
    }
    const Pokemon& getPokemonAt(int index) const {
        return pokemons.at(index);
    }
    int getPokemonsCount() const {
        return pokemons.size();
    }
    const vector<Pokemon>& getPokemons() const {
        return pokemons;
    }

public:
    virtual Pokemon* getPokemonByIndex(int index)  = 0;
    virtual Pokemon* getPokemonByName(string name)  = 0;
    void displayAllPokemons() ;
};