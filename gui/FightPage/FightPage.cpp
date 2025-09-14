#include "FightPage.hpp"

#include "FightPage.hpp"
#include "../HomePage/HomePage.hpp"

FightPage::FightPage() : CenteredActionPage() {
    text_.setString("Fight");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Red);

    setButtonSize({220.f, 64.f});
    setButtonColors(sf::Color(178, 34, 34), sf::Color::Black, 2.f); // FireBrick
    setButtonText("Continue", 32, sf::Color::White);
}

std::unique_ptr<BasePage> FightPage::next() {
    // Exemple: retour à la HomePage après clic
    return std::make_unique<class HomePage>();
}
