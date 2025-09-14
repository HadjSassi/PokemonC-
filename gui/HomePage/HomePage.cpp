#include "HomePage.hpp"
#include "../RandomPage/RandomPage.hpp"

HomePage::HomePage() : CenteredActionPage() {
    text_.setString("Page principale");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Green);

    setButtonSize({220.f, 64.f});
    setButtonColors(sf::Color(30, 144, 255), sf::Color::Black, 2.f);
    setButtonText("Play", 32, sf::Color::White);
    setVerticalMargin(24.f);
}

std::unique_ptr<BasePage> HomePage::next() {
    return std::make_unique<class RandomPage>();
}
