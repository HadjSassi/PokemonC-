#include "../headers/Pokedex.hpp"
#include <cctype>

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
    bool firstLine = true;
    while (getline(fichier, ligne)) {
        if (ligne.empty()) continue;
        stringstream ss(ligne);
        string champ;
        vector<string> champs;
        while (getline(ss, champ, ',')) {
            champs.push_back(champ);
        }
        if (firstLine && !isdigit(champs[0][0])) {
            firstLine = false;
            continue;
        }
        firstLine = false;
        if (champs.size() > 11) {
            try {
                addPokemon(Pokemon(
                    stoi(champs[0]), champs[1], stod(champs[5]),
                    stod(champs[6]), stod(champs[7]),
                    stoi(champs[11]), stoi(champs[4])
                ));
            } catch (const std::exception &e) {
                cerr << "Erreur de parsing ligne: " << ligne << " (" << e.what() << ")" << endl;
            }
        }
    }
}

void Pokedex::displayAllPokemons() {
    cout << "All Pokemons in the Pokedex:" << endl;
    for (Pokemon pokemon: getPokemons()) {
        pokemon.displayInfo();
    }
    cout << "-----------------------" << endl;
}
