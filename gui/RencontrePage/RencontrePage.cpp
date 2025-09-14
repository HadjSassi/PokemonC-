#include "RencontrePage.hpp"
#include "../HomePage/HomePage.hpp"
#include <SFML/Window.hpp>

RencontrePage::RencontrePage() : CenteredActionPage() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 898);
    pokemonId = distrib(gen);

    std::string path = "../resources/img/pokemons/" + std::to_string(pokemonId) + ".png";
    if (pokemonTexture.loadFromFile(path)) {
        pokemonSprite.setTexture(pokemonTexture);
    }
    text_.setString("Rencontre");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Cyan);

    setButtonSize({220.f, 64.f});
    setButtonColors(sf::Color(30, 144, 255), sf::Color::Black, 2.f);
    setButtonText("Capture", 32, sf::Color::White);
}

unique_ptr<BasePage> RencontrePage::next() {
    return make_unique<class HomePage>();
}

void RencontrePage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    CenteredActionPage::draw(target, states);

    sf::Vector2u texSize = pokemonTexture.getSize();
    sf::Vector2u winSize = target.getSize();
    float scale = static_cast<float>(winSize.y) / texSize.y;

    sf::Sprite scaledSprite = pokemonSprite;
    scaledSprite.setScale(-scale, scale);
    scaledSprite.setPosition(static_cast<float>(texSize.x * scale), 0);

    target.draw(scaledSprite, states);
}