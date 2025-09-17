#include "Popup.hpp"
#include "../../../config.hpp"
Popup::Popup(const sf::Font& font) {
    text.setFont(font);
    text.setCharacterSize(CHARACTER_SIZE);
    text.setFillColor(sf::Color::White);

    buttonText.setFont(font);
    buttonText.setCharacterSize(BUTTON_CHARACTER_SIZE);
    buttonText.setFillColor(sf::Color::White);

    box.setFillColor(sf::Color(50, 50, 50, 220));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(BUTTON_LINE_THICKNESS);

    button.setSize({BUTTON1_X_SIZE, BUTTON1_Y_SIZE});
    button.setFillColor(sf::Color(30, 144, 255));
}

void Popup::show(const std::string& message, const std::string& btnText) {
    visible = true;
    buttonClicked = false;
    text.setString(message);
    buttonText.setString(btnText);
}

void Popup::hide() {
    visible = false;
}

bool Popup::isVisible() const {
    return visible;
}

void Popup::updateLayout(sf::Vector2u winSize) {
    auto bounds = text.getLocalBounds();
    float marginX = BUTTON_MARGIN, marginY = BUTTON_MARGIN;
    float popupWidth = bounds.width + BUTTON_LINE_THICKNESS * marginX;
    float popupHeight = bounds.height + BUTTON_LINE_THICKNESS * marginY + POP_UP_MARGIN;

    float x, y;
    if (customPosition_) {
        x = customPosition_->x;
        y = customPosition_->y;
    } else {
        x = winSize.x - popupWidth - BUTTON_MARGIN;
        y = (winSize.y - popupHeight) / BUTTON_LINE_THICKNESS;
    }
    box.setSize({popupWidth, popupHeight});
    box.setPosition(x, y);

    text.setPosition(
        x + (popupWidth - bounds.width) / BUTTON_LINE_THICKNESS - bounds.left,
        y + TEXT_MARGIN
    );

    button.setPosition(
        x + (popupWidth - button.getSize().x) / BUTTON_LINE_THICKNESS,
        y + popupHeight - button.getSize().y - BUTTON_PADDING
    );
    auto btnBounds = buttonText.getLocalBounds();
    buttonText.setPosition(
        button.getPosition().x + (button.getSize().x - btnBounds.width) / BUTTON_LINE_THICKNESS - btnBounds.left,
        button.getPosition().y + (button.getSize().y - btnBounds.height) / BUTTON_LINE_THICKNESS - btnBounds.top
    );
}

void Popup::draw(sf::RenderTarget& target) const {
    if (!visible) return;
    sf::Vector2u winSize = target.getSize();
    const_cast<Popup*>(this)->updateLayout(winSize);
    target.draw(box);
    target.draw(text);
    target.draw(button);
    target.draw(buttonText);
}

bool Popup::handleEvent(const sf::Event& event, sf::Vector2u winSize) {
    if (!visible) return false;
    updateLayout(winSize);
    if (event.type == sf::Event::MouseButtonPressed) {
        auto mouse = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        if (button.getGlobalBounds().contains(mouse)) {
            buttonClicked = true;
            return true;
        }
    }
    return false;
}

void Popup::setPosition(const sf::Vector2f& pos) {
    customPosition_ = pos;
}

bool Popup::wasButtonClicked() const {
    return buttonClicked;
}