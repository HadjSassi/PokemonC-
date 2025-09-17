#ifndef POKEMON_CONFIG_HPP
#define POKEMON_CONFIG_HPP

/*
 * Numbers
 */
const int FIRST_FIELD_INDEX = 0;
const int FIRST_VALUE = 0;
const int LIFE_HEALTH_VALUE = 0;
const int MAX_POKEMON_PER_PARTY = 6;
const int DEFAULT_RANDOM_SEED = 42;
const int MAX_POKEMON_IN_PARTY = 6;

/*
 * Strings and chars
 */
const char COMMA = ',';
const string SEPERATOR = "-----------------------";
const string OPENING_PARANTHESIS = " (";
const string CLOSING_PARANTHESIS = ")";

const string ID = "ID: ";
const string NAME = "Name: ";
const string HIT_POINTS = "Hit Points: ";
const string ATTACK = "Attack: ";
const string DEFENSE = "Defense: ";
const string GENERATION = "Generation: ";

const string POKEDEX_POKEMONS = "All Pokemons in the Pokedex:";
const string PARTY_POKEMONS = "All Pokemons in the party :";
const string ATTACK_POKEMONS = "All Pokemons in the attack team:";

const string PARSING_LINE_ERROR = "Erreur de parsing ligne: ";
const string NUMBER_POKEMONS_NOT_RESPECTED = "Number of pokemons must be between 1 and ";
const string NUMBER_POKEMONS_NOT_ENOUGH = "Not enough pokemons in party to create the attack set";
const string ID_NOT_FOUND = "Id introuvable";
const string NAME_NOT_FOUND = "Nom introuvable";
const string POKEMON_NOT_FOUND = "Pokemon introuvable: ";
const string INDEX_OUT_OF_RANGE = "Index out of range: ";


/*
 * File paths
 */
const string DATABASE_PATH = "../resources/database/pokedex.csv";


#endif //POKEMON_CONFIG_HPP