#include "../headers/Pokedex.hpp"

Pokedex *Pokedex::instance = nullptr;

Pokedex *Pokedex::getInstance() {
    if (instance == nullptr) {
        instance = new Pokedex();
    }
    return instance;
}

Pokedex::Pokedex() {
    ifstream fichier(chemin);
    string ligne;
    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        string champ;
        vector<string> champs;
        while (getline(ss, champ, ',')) {
            champs.push_back(champ);
        }
        if (!champs.empty()) {
            addPokemon(Pokemon(stoi(champs[0]), champs[1], stod(champs[5]), stod(champs[6]), stod(champs[7]),
                                       stoi(champs[11]), stoi(champs[4])));
        }
    }
}

Pokemon* Pokedex::getPokemonByIndex(int index) {
    if (index >= 0 && index < getPokemonsCount()) {
        return new Pokemon(getPokemonAt(index));
    }
    throw out_of_range("Index out of range");
}

Pokemon* Pokedex::getPokemonByName(string name) {
    for (const Pokemon &pokemon: getPokemons()) {
        if (pokemon.getName() == name) {
            return new Pokemon(pokemon);
        }
    }
    throw invalid_argument("Pokemon not found");
}
