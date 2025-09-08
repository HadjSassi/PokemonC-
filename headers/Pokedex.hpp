#include "PokemonVector.hpp"
#include <fstream>
#include <sstream>
#include <string>

const string chemin = "database/pokedex.csv";

class Pokedex: public PokemonVector {
private:
    static Pokedex* instance;
    Pokedex();

public:
    Pokemon* getPokemonByIndex(int index);
    Pokemon* getPokemonByName(string name);
    static Pokedex* getInstance();
};
