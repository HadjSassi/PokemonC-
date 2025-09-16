#ifndef POKEMON_POPUP_HPP
#define POKEMON_POPUP_HPP

#include <optional>
#include <SFML/Graphics.hpp>
#include <string>

class Popup {
public:
    Popup(const sf::Font& font);

    void show(const std::string& message, const std::string& buttonText = "OK");
    void hide();
    bool isVisible() const;

    void draw(sf::RenderTarget& target) const;
    bool handleEvent(const sf::Event& event, sf::Vector2u winSize);
    void setPosition(const sf::Vector2f& pos);

    bool wasButtonClicked() const;

private:
    bool visible = false;
    bool buttonClicked = false;
    sf::RectangleShape box;
    sf::Text text;
    sf::RectangleShape button;
    sf::Text buttonText;
    std::optional<sf::Vector2f> customPosition_;

    void updateLayout(sf::Vector2u winSize);
};


#endif //POKEMON_POPUP_HPP