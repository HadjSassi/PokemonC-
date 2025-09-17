#ifndef POKEMON_CONFIG_HPP
#define POKEMON_CONFIG_HPP
#include <string>

using namespace std;
/*
 * Numbers
 */
const int FIRST_FIELD_INDEX = 0;
const int FIRST_VALUE = 0;
const int SECOND_VALUE = 1;
const int NOT_FOUND = -1;
const int LIFE_HEALTH_VALUE = 0;
const int MAX_POKEMON_PER_PARTY = 6;
const int DEFAULT_RANDOM_SEED = 42;
const int MAX_POKEMON_IN_PARTY = 6;

const float BUTTON_X_SIZE = 220.f;
const float BUTTON_Y_SIZE = 64.f;
const float BUTTON1_X_SIZE = 160.f;
const float BUTTON1_Y_SIZE = 50.f;
const float LINE_THICKNESS = 2.f;
const float BUTTON_LINE_MARGIN = 4.f;
const float BUTTON_MARGIN = 40.f;
const float BUTTON_PADDING = 20.f;
const float POP_UP_MARGIN = 70.f;
const float TEXT_MARGIN = 30.f;
const float MARGIN = 24.f;
const int LITTLE_CHARACTER_SIZE = 28;
const int CHARACTER_SIZE = 32;
const int BIG_CHARACTER_SIZE = 58;
const int LABEL_CHARACTER_SIZE = 18;
const int BUTTON_CHARACTER_SIZE = 28;
const float SCROLL_OFFSET = 0.f;
const int HEADER_HEIGHT = 36;
const int ITEM_HEIGHT = 24;
const int SEARCH_TEXT_X_MARGIN = 8;
const float SEARCH_TEXT_MARGIN = 8.f;
const int SEARCH_TEXT_Y_MARGIN = 6;
const float SEARCH_BAR_SCALE = 1.f;
const float LABEL_OFFSET = 36.f;
const float FPS = 24.0f;
const float FRAME_FREQUENCY = 1.0f;
const float BUTTON_POSITION_X = 1000.f;
const float BUTTON_POSITION_Y = 900.f;
const float POP_UP_POSITION_X = 600.f;
const float POP_UP_POSITION_Y = 400.f;
const float TABLE_OFFSET_Y = 200.f;
const float ROW_HEIGHT = 120.f;
const float IMAGE_SIZE = 60.f;
const int IMAGE_PADDING = 8;
const float SELECT_BOX_X_POSITION = 50.f;
const float SELECT_BOX_Y_POSITION = 100.f;
const float SELECT_BOX_WIDTH = 200.f;
const float SELECT_BOX_HEIGHT = 400.f;
const float SPRITE_SCALE_FACTOR = 100.f;
const float COLUMN_OFFSET = 500.f;

const int FIRST_POKEMON_ID = 1;
const int LAST_POKEMON_ID = 799;

const int BACKSPACE_KEY = 8;
const int ENTER_KEY = 13;
const int FIRST_KEY = 32;
const int LAST_KEY = 128;
/*
 * Strings and chars
 */
const char COMMA = ',';
const string SEPERATOR = "-----------------------";
const string OPENING_PARANTHESIS = " (";
const string CLOSING_PARANTHESIS = ")";

const string WINDOW_TITLE = "POKEMON the Game!";
const string BUTTON_LABEL_ACTION = "Action";
const string POP_UP_BUTTON_LABEL_ACTION = "OK";
const string SEARCH_BAR_TEXT = "Recherche: ";
const string FIGHTING_BUTTON_TEXT = "Fight";
const string FIGHT_BUTTON_TEXT = "To Fight";
const string PROCEED_BUTTON_TEXT = "Proceed";
const string PAGE_PRICNIPAL_TEXT = "Page principale";
const string START_GAME = "PLAY!";
const string EXPLORATION_TEXT = "Exploration ...";
const string RENCONTRE_TEXT = "Rencontre";
const string CAPTURE_BUTTON_TEXT = "Capture";

const string JPG = ".jpg";
const string PNG = ".png";
const string CSV = ".csv";

const string ID = "ID: ";
const string NAME = "Name: ";
const string HIT_POINTS = "Hit Points: ";
const string ATTACK = "Attack: ";
const string DEFENSE = "Defense: ";
const string GENERATION = "Generation: ";

const string WON = "Won: ";
const string AND = " and ";
const string LOST = "Lost: ";
const string POKEMONS = " Pokemons.";
const string ESCAPED_POKEMONS = "Pokemon flew unfortunately";
const string CAPTURED_POKEMONS = "Congratulation Pokemon well captured";

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
const string NO_FRAME_FOUND = "No frames found in: ";

/*
 * File paths
 */
const string DATABASE_PATH = "../resources/database/pokedex.csv";
const string VERSUS_IMAGE_PATH = "../resources/img/versusSmall.png";
const string IMAGES_PATH = "../resources/img/pokemons/";
const string EXPLORATION_VID_PATH = "../resources/vid/exploration";
const string OPENING_VID_PATH = "../resources/vid/throw";
const string ENDING_VID_PATH = "../resources/vid/fadingOut";
const string FONT_PATH = "../resources/font/arial.ttf";
const string WALLPAPER_PATH = "../resources/img/wallpaper.png";
const string MUSIC_PATH = "../resources/music/son.mp3";
#endif //POKEMON_CONFIG_HPP