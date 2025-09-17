#include "RandomPage.hpp"

#include "../../entities/headers/PokemonParty.hpp"
#include "../RencontrePage/RencontrePage.hpp"
#include "../FightPage/FightPage.hpp"
#include "../../config.hpp"

RandomPage::RandomPage() : BasePage() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(FIRST_VALUE, SECOND_VALUE);
    value_ = dist(gen);

    text_.setString(EXPLORATION_TEXT);
    text_.setCharacterSize(BIG_CHARACTER_SIZE);
    text_.setFillColor(sf::Color::Black);

    video_ = std::make_unique<VideoPlayer>(EXPLORATION_VID_PATH, FPS/2);
    isWallpaper = false;
}


bool RandomPage::isFinished() const {
    return video_->isFinished();
}

unique_ptr<BasePage> RandomPage::next() {
    if ( PokemonParty::getInstance().getPokemonsCount() == FIRST_VALUE || value_ % 2 == FIRST_VALUE) {
    // if ( PokemonParty::getInstance().getPokemonsCount() == 0) {
        return make_unique<class RencontrePage>();
    } else {
        return make_unique<class FightPage>();
    }
}

unique_ptr<BasePage> RandomPage::previous() {
    return BasePage::previous();
}

void RandomPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (video_) target.draw(*video_, states);
    BasePage::draw(target, states);
}

void RandomPage::update() {
    if (video_) video_->update();
}