#include "CenteredActionPage.hpp"
#include "../../config.hpp"
CenteredActionPage::CenteredActionPage() : BasePage() {
    button_.setSize({BUTTON_X_SIZE, BUTTON_Y_SIZE});
    button_.setFillColor(sf::Color(30, 144, 255));
    button_.setOutlineThickness(BUTTON_LINE_THICKNESS);
    button_.setOutlineColor(sf::Color::Black);

    label_.setFont(font_);
    label_.setString(BUTTON_LABEL_ACTION);
    label_.setCharacterSize(CHARACTER_SIZE);
    label_.setFillColor(sf::Color::White);
    centerLabelInButton();
}

void CenteredActionPage::setButtonSize(const sf::Vector2f &size) {
    button_.setSize(size);
    centerLabelInButton();
}

void CenteredActionPage::setButtonPosition(const sf::Vector2f& pos) {
    buttonPosition_ = pos;
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
    label_.setOrigin(lb.left + lb.width / BUTTON_LINE_THICKNESS, lb.top + lb.height / BUTTON_LINE_THICKNESS);
}

void CenteredActionPage::handleEvent(const sf::Event &event, sf::Vector2u winSize) {
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

    sf::RectangleShape button = button_;
    const sf::Vector2f bsize = button.getSize();
    button.setOrigin(bsize.x / BUTTON_LINE_THICKNESS, bsize.y / BUTTON_LINE_THICKNESS);

    sf::Vector2f pos;
    if (buttonPosition_) {
        pos = *buttonPosition_;
    } else {
        const auto tb = text_.getLocalBounds();
        const float textHalfH = tb.top + tb.height / BUTTON_LINE_THICKNESS;
        pos = {center.x, center.y + textHalfH + margin_ + bsize.y / BUTTON_LINE_THICKNESS};
    }
    button.setPosition(pos);

    sf::Text label = label_;
    label.setPosition(button.getPosition().x, button.getPosition().y - BUTTON_LINE_MARGIN);

    buttonBounds_ = button.getGlobalBounds();

    target.draw(button, states);
    target.draw(label, states);
}

void CenteredActionPage::update() {}
