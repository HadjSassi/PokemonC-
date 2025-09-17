#include "HomePage.hpp"
#include "../RandomPage/RandomPage.hpp"

HomePage::HomePage() : CenteredActionPage() {
    text_.setString(PAGE_PRICNIPAL_TEXT);
    text_.setCharacterSize(BIG_CHARACTER_SIZE);
    text_.setFillColor(sf::Color::Green);

    setButtonSize({BUTTON_X_SIZE, BUTTON_Y_SIZE});
    setButtonColors(sf::Color(30, 144, 255), sf::Color::Black, 2.f);
    setButtonText(START_GAME, CHARACTER_SIZE, sf::Color::White);
    setVerticalMargin(MARGIN);
}

unique_ptr<BasePage> HomePage::next() {
    return make_unique<class RandomPage>();
}

unique_ptr<BasePage> HomePage::previous() {
    return CenteredActionPage::previous();
}

void HomePage::update() {}
