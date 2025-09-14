#include "HomePage.hpp"
#include "../RandomPage/RandomPage.hpp"

HomePage::HomePage() : BasePage() {
    text_.setString("Page principale");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Green);

    playButton_.setSize({220.f, 64.f});
    playButton_.setFillColor(sf::Color(30, 144, 255)); // DodgerBlue
    playButton_.setOutlineThickness(2.f);
    playButton_.setOutlineColor(sf::Color::Black);

    playText_.setFont(font_);
    playText_.setString("Play");
    playText_.setCharacterSize(32);
    playText_.setFillColor(sf::Color::White);

    layoutButton();
}

void HomePage::layoutButton() {
    auto bounds = playText_.getLocalBounds();
    playText_.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
    sf::Vector2f pos = playButton_.getPosition();
    sf::Vector2f size = playButton_.getSize();
    playText_.setPosition(pos.x + size.x / 2.f, pos.y + size.y / 2.f - 4.f);
}

void HomePage::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {

        sf::Vector2f mpos(static_cast<float>(event.mouseButton.x),
                          static_cast<float>(event.mouseButton.y));

        if (buttonBounds_.contains(mpos)) {
            clicked_ = true;
            playButton_.setFillColor(sf::Color(24, 116, 205));
        }
        }
}

bool HomePage::isFinished() const {
    return clicked_;
}

std::unique_ptr<BasePage> HomePage::next() {
    return std::make_unique<class RandomPage>();
}

void HomePage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    BasePage::draw(target, states);

    const sf::View& view = target.getView();
    const sf::Vector2f center = view.getCenter();

    const auto tb = text_.getLocalBounds();
    const float textHalfH = tb.top + tb.height / 2.f;

    const float margin = 24.f;

    sf::RectangleShape button = playButton_;
    const sf::Vector2f bsize = button.getSize();
    button.setOrigin(bsize.x / 2.f, bsize.y / 2.f);
    button.setPosition(center.x, center.y + textHalfH + margin + bsize.y / 2.f);

    sf::Text label = playText_;
    const auto lb = label.getLocalBounds();
    label.setOrigin(lb.left + lb.width / 2.f, lb.top + lb.height / 2.f);
    label.setPosition(button.getPosition().x, button.getPosition().y - 4.f);

    buttonBounds_ = button.getGlobalBounds();

    target.draw(button, states);
    target.draw(label, states);
}