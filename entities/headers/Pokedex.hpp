#ifndef POKEDEX_HPP
#define POKEDEX_HPP
#include "PokemonVector.hpp"
#include "../../config.hpp"
#include <fstream>
#include <sstream>
#include <string>

const string chemin = DATABASE_PATH;

class Pokedex : public PokemonVector {
public:
    static Pokedex *getInstance();

    void displayAllPokemons() override;

private:
    static Pokedex *instance;

    Pokedex();
};
#endif // POKEDEX_HPP
