
#include "RandomPage.hpp"
#include "../MeetingPage/RencontrePage.hpp"
#include "../FightPage/FightPage.hpp"

RandomPage::RandomPage() : BasePage() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 99);
    value_ = dist(gen);

    text_.setString("Nombre: " + std::to_string(value_));
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Yellow);
}


bool RandomPage::isFinished() const {
    return clock_.getElapsedTime().asSeconds() > 3.0f;
}

std::unique_ptr<BasePage> RandomPage::next() {
    if (value_ % 2 == 0) {
        return std::make_unique<class RencontrePage>();
    } else {
        return std::make_unique<class FightPage>();
    }
}