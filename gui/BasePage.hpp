//
// Created by mahdihadjsassi on 12/09/2025.
//
#ifndef BASEPAGE_HPP
#define BASEPAGE_HPP

#include <SFML/Graphics.hpp>

class BasePage : public sf::Drawable {
public:
    BasePage();
    virtual void update() = 0;
protected:
    sf::Text text_;
    sf::Font font_;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
#endif // BASEPAGE_HPP
