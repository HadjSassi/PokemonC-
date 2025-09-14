#include "CenteredActionPage.hpp"

CenteredActionPage::CenteredActionPage() : BasePage() {
    button_.setSize({220.f, 64.f});
    button_.setFillColor(sf::Color(30, 144, 255));
    button_.setOutlineThickness(2.f);
    button_.setOutlineColor(sf::Color::Black);

    label_.setFont(font_);
    label_.setString("Action");
    label_.setCharacterSize(32);
    label_.setFillColor(sf::Color::White);
    centerLabelInButton();
}

void CenteredActionPage::setButtonSize(const sf::Vector2f &size) {
    button_.setSize(size);
    centerLabelInButton();
}

void CenteredActionPage::setButtonColors(const sf::Color &fill, const sf::Color &outline, float outlineThickness) {
    button_.setFillColor(fill);
    button_.setOutlineColor(outline);
    button_.setOutlineThickness(outlineThickness);
}

void CenteredActionPage::setButtonText(const sf::String &s, unsigned int charSize, const sf::Color &color) {
    label_.setString(s);
    label_.setCharacterSize(charSize);
    label_.setFillColor(color);
    centerLabelInButton();
}

void CenteredActionPage::setVerticalMargin(float margin) {
    margin_ = margin;
}

void CenteredActionPage::centerLabelInButton() {
    const auto lb = label_.getLocalBounds();
    label_.setOrigin(lb.left + lb.width / 2.f, lb.top + lb.height / 2.f);
}

void CenteredActionPage::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mpos(static_cast<float>(event.mouseButton.x),
                          static_cast<float>(event.mouseButton.y));

        if (buttonBounds_.contains(mpos)) {
            onButtonClicked();
        }
    }
}

void CenteredActionPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    BasePage::draw(target, states);

    const sf::View &view = target.getView();
    const sf::Vector2f center = view.getCenter();

    const auto tb = text_.getLocalBounds();
    const float textHalfH = tb.top + tb.height / 2.f;

    sf::RectangleShape button = button_;
    const sf::Vector2f bsize = button.getSize();
    button.setOrigin(bsize.x / 2.f, bsize.y / 2.f);
    button.setPosition(center.x, center.y + textHalfH + margin_ + bsize.y / 2.f);

    sf::Text label = label_;
    label.setPosition(button.getPosition().x, button.getPosition().y - 4.f);

    buttonBounds_ = button.getGlobalBounds();

    target.draw(button, states);
    target.draw(label, states);
}

void CenteredActionPage::update() {}
