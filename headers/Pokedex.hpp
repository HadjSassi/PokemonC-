#include "PokemonVector.hpp"
#include <fstream>
#include <sstream>
#include <string>

const string chemin = "../resources/database/pokedex.csv";

class Pokedex: public PokemonVector {
private:
    static Pokedex* instance;
    Pokedex();

public:
    static Pokedex* getInstance();
    void displayAllPokemons() override;
};
