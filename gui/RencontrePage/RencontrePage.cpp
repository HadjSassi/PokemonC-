#include "RencontrePage.hpp"
#include "../HomePage/HomePage.hpp"
#include <SFML/Window.hpp>
#include "../../entities/headers/Pokedex.hpp"
#include "../../entities/headers/PokemonParty.hpp"

RencontrePage::RencontrePage() : CenteredActionPage(), popup(*text_.getFont()) {
    selectRandomPokemon();

    text_.setString(RENCONTRE_TEXT);
    text_.setCharacterSize(BIG_CHARACTER_SIZE);
    text_.setFillColor(sf::Color::Yellow);

    setButtonSize({BUTTON_X_SIZE, BUTTON_Y_SIZE});
    setButtonColors(sf::Color(30, 144, 255), sf::Color::Black, 2.f);
    setButtonText(CAPTURE_BUTTON_TEXT, CHARACTER_SIZE, sf::Color::White);
}

void RencontrePage::selectRandomPokemon() {
    do {
        Pokedex *pokedex = Pokedex::getInstance();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(FIRST_POKEMON_ID, LAST_POKEMON_ID);
        // std::uniform_int_distribution<> distrib(1, 10);
        pokemonId = distrib(gen);
        pokemon = pokedex->getPokemonByIndex(pokemonId);
        std::string path = IMAGES_PATH + std::to_string(pokemon->getId()) + PNG;
        if (pokemonTexture.loadFromFile(path)) {
            pokemonSprite.setTexture(pokemonTexture);
        }
    } while (PokemonParty::getInstance().hasPokemonWithId(pokemonId));
}

unique_ptr<BasePage> RencontrePage::next() {
    return make_unique<class HomePage>();
}

unique_ptr<BasePage> RencontrePage::previous() {
    return CenteredActionPage::previous();
}

void RencontrePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Vector2u texSize = pokemonTexture.getSize();
    sf::Vector2u winSize = target.getSize();
    float scale = static_cast<float>(winSize.y) / texSize.y;

    sf::Sprite scaledSprite = pokemonSprite;
    scaledSprite.setScale(-scale, scale);
    scaledSprite.setPosition(static_cast<float>(texSize.x * scale), FIRST_VALUE);

    sf::Text infoText;
    infoText.setFont(*text_.getFont());
    if (pokemon) infoText.setString(pokemon->getInfoString());
    infoText.setCharacterSize(LITTLE_CHARACTER_SIZE);
    infoText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = infoText.getLocalBounds();
    float x = winSize.x - textRect.width - IMAGE_SIZE;
    float y = (winSize.y - textRect.height) / LINE_THICKNESS;
    infoText.setPosition(x, y);

    CenteredActionPage::draw(target, states);
    target.draw(scaledSprite, states);
    target.draw(infoText, states);
    popup.draw(target);
}

void RencontrePage::onButtonClicked() {
    int result = std::rand() % 2;
    if (result == FIRST_VALUE)
        popup.show(ESCAPED_POKEMONS);
    else {
        PokemonParty::getInstance().addPokemonToParty(*pokemon);
        popup.show(CAPTURED_POKEMONS);
    }
}

void RencontrePage::handleEvent(const sf::Event &event, sf::Vector2u winSize) {
    if (popup.isVisible()) {
        if (popup.handleEvent(event, winSize) && popup.wasButtonClicked()) {
            CenteredActionPage::onButtonClicked();
            popup.hide();
        }
    } else {
        CenteredActionPage::handleEvent(event, winSize);
    }
}
