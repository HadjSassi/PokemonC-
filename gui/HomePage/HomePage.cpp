//
// Created by mahdihadjsassi on 12/09/2025.
//

#include "HomePage.hpp"

HomePage::HomePage() : BasePage() {
    text_.setString("Page principale");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Green);
    text_.setPosition(180, 250);
}

void HomePage::update() {}