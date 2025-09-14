//
// Created by mahdihadjsassi on 12/09/2025.
//

#include "BasePage.hpp"

BasePage::BasePage() {
    font_.loadFromFile("../resources/font/arial.ttf");
    text_.setFont(font_);
}

void BasePage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text_, states);
}