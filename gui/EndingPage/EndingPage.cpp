#include "EndingPage.hpp"
#include "../HomePage/HomePage.hpp"

EndingPage::EndingPage() : BasePage() {
    video_ = std::make_unique<VideoPlayer>(ENDING_VID_PATH, FPS/2);
    isWallpaper = false;
}

bool EndingPage::isFinished() const {
    return video_->isFinished();
}

unique_ptr<BasePage> EndingPage::next() {
    return make_unique<class HomePage>();
}

unique_ptr<BasePage> EndingPage::previous() {
    return BasePage::previous();
}

void EndingPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (video_) target.draw(*video_, states);
    BasePage::draw(target, states);
}

void EndingPage::update() {
    if (video_) video_->update();
}