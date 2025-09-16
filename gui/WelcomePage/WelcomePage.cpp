#include "WelcomePage.hpp"
#include "../HomePage/HomePage.hpp"

WelcomePage::WelcomePage() : BasePage() {
    text_.setString("POKEMON the Game!");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::White);
    video_ = std::make_unique<VideoPlayer>("../resources/vid/throw", 15.0f);
    isWallpaper = false;
}

bool WelcomePage::isFinished() const {
    return video_->isFinished();
}

unique_ptr<BasePage> WelcomePage::next() {
    return make_unique<class HomePage>();
}

unique_ptr<BasePage> WelcomePage::previous() {
    return BasePage::previous();
}

void WelcomePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (video_) target.draw(*video_, states);
    BasePage::draw(target, states);
}

void WelcomePage::update() {
    if (video_) video_->update();
}
