#include "RencontrePage.hpp"
#include "../HomePage/HomePage.hpp"

RencontrePage::RencontrePage() : CenteredActionPage() {
    text_.setString("Rencontre");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Cyan);

    setButtonSize({220.f, 64.f});
    setButtonColors(sf::Color(30, 144, 255), sf::Color::Black, 2.f);
    setButtonText("Continue", 32, sf::Color::White);
}

std::unique_ptr<BasePage> RencontrePage::next() {
    // Exemple: retour à la HomePage après clic
    return std::make_unique<class HomePage>();
}