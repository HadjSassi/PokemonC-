#include <vector>
#include "Pokemon.hpp"
#include <fstream>


using namespace std;
using std::vector;

class PokemonVector {

private:
    vector<Pokemon> pokemons;

protected:
    void addPokemon(const Pokemon& pokemon) ;
    const Pokemon& getPokemonAt(int index) const ;
    int getPokemonsCount() const ;
    const vector<Pokemon>& getPokemons() const ;

public:
    Pokemon* getPokemonByIndex(int index) ;
    Pokemon* getPokemonByName(string name);
    void displayAllPokemons() ;
};