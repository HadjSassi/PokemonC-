//
// Created by mahdihadjsassi on 12/09/2025.
//

#include "WelcomePage.hpp"

WelcomePage::WelcomePage() : BasePage() {
    text_.setString("POKEMON the Game!");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::White);
    text_.setPosition(200, 250);
}

bool WelcomePage::isTimeUp() const {
    return clock_.getElapsedTime().asSeconds() > 1.0f;
}

void WelcomePage::update() {}