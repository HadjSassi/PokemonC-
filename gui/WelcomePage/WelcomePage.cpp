
#include "WelcomePage.hpp"
#include "../HomePage/HomePage.hpp"

WelcomePage::WelcomePage() : BasePage() {
    text_.setString("POKEMON the Game!");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::White);
}

bool WelcomePage::isFinished() const {
    return clock_.getElapsedTime().asSeconds() > 1.0f;
}

std::unique_ptr<BasePage> WelcomePage::next() {
    return std::make_unique<class HomePage>();
}
