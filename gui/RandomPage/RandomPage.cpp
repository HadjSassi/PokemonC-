#include "RandomPage.hpp"
#include "../RencontrePage/RencontrePage.hpp"
#include "../FightPage/FightPage.hpp"

RandomPage::RandomPage() : BasePage() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 99);
    value_ = dist(gen);

    text_.setString("Exploration ...");
    text_.setCharacterSize(58);
    text_.setFillColor(sf::Color::Black);

    video_ = std::make_unique<VideoPlayer>("../resources/vid/exploration", 15.0f);
}


bool RandomPage::isFinished() const {
    // return clock_.getElapsedTime().asSeconds() > 3.0f;
    return video_->isFinished();
}

unique_ptr<BasePage> RandomPage::next() {
    if (value_ % 2 == 0) {
        return make_unique<class RencontrePage>();
    } else {
        return make_unique<class FightPage>();
    }
}

void RandomPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (video_) target.draw(*video_, states);
    BasePage::draw(target, states);
}

void RandomPage::update() {
    if (video_) video_->update();
}