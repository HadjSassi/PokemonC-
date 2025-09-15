#include "RencontrePage.hpp"
#include "../HomePage/HomePage.hpp"
#include <SFML/Window.hpp>
#include "../../entities/headers/Pokedex.hpp"
#include "../../entities/headers/PokemonParty.hpp"

RencontrePage::RencontrePage() : CenteredActionPage(), popup(*text_.getFont()) {
    selectRandomPokemon();

    text_.setString("Rencontre");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Yellow);

    setButtonSize({220.f, 64.f});
    setButtonColors(sf::Color(30, 144, 255), sf::Color::Black, 2.f);
    setButtonText("Capture", 32, sf::Color::White);
}

void RencontrePage::selectRandomPokemon() {
    do {
        Pokedex *pokedex = Pokedex::getInstance();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 799);
        // std::uniform_int_distribution<> distrib(1, 10);
        pokemonId = distrib(gen);
        pokemon = pokedex->getPokemonByIndex(pokemonId);
        std::string path = "../resources/img/pokemons/" + std::to_string(pokemonId) + ".png";
        if (pokemonTexture.loadFromFile(path)) {
            pokemonSprite.setTexture(pokemonTexture);
        }
    } while (PokemonParty::getInstance()->hasPokemonWithId(pokemonId));
}

unique_ptr<BasePage> RencontrePage::next() {
    return make_unique<class HomePage>();
}

void RencontrePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Vector2u texSize = pokemonTexture.getSize();
    sf::Vector2u winSize = target.getSize();
    float scale = static_cast<float>(winSize.y) / texSize.y;

    sf::Sprite scaledSprite = pokemonSprite;
    scaledSprite.setScale(-scale, scale);
    scaledSprite.setPosition(static_cast<float>(texSize.x * scale), 0);

    sf::Text infoText;
    infoText.setFont(*text_.getFont());
    if (pokemon) infoText.setString(pokemon->getInfoString());
    infoText.setCharacterSize(28);
    infoText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = infoText.getLocalBounds();
    float x = winSize.x - textRect.width - 60.f;
    float y = (winSize.y - textRect.height) / 2.f;
    infoText.setPosition(x, y);

    CenteredActionPage::draw(target, states);
    target.draw(scaledSprite, states);
    target.draw(infoText, states);
    popup.draw(target);
}

void RencontrePage::onButtonClicked() {
    int result = std::rand() % 2;
    if (result == 0)
        popup.show("Pokemon flew unfortunately");
    else {
        PokemonParty::getInstance()->addPokemonToParty(*pokemon);
        popup.show("Congratulation Pokemon well captured");
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
