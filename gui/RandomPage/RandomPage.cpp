#include "RandomPage.hpp"
#include "../RencontrePage/RencontrePage.hpp"
#include "../FightPage/FightPage.hpp"

RandomPage::RandomPage() : BasePage() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 99);
    value_ = dist(gen);

    text_.setString("Exploration ...");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Yellow);
}


bool RandomPage::isFinished() const {
    return clock_.getElapsedTime().asSeconds() > 3.0f;
}

unique_ptr<BasePage> RandomPage::next() {
    if (value_ % 2 == 0) {
        return make_unique<class RencontrePage>();
    } else {
        return make_unique<class FightPage>();
    }
}
