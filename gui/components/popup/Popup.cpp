#include "Popup.hpp"

Popup::Popup(const sf::Font& font) {
    text.setFont(font);
    text.setCharacterSize(32);
    text.setFillColor(sf::Color::White);

    buttonText.setFont(font);
    buttonText.setCharacterSize(28);
    buttonText.setFillColor(sf::Color::White);

    box.setFillColor(sf::Color(50, 50, 50, 220));
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(2);

    button.setSize({160, 50});
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
    float marginX = 40.f, marginY = 40.f;
    float popupWidth = bounds.width + 2 * marginX;
    float popupHeight = bounds.height + 2 * marginY + 70.f;

    float x = winSize.x - popupWidth - 40;
    float y = (winSize.y - popupHeight) / 2.f;
    box.setSize({popupWidth, popupHeight});
    box.setPosition(x, y);

    text.setPosition(
        x + (popupWidth - bounds.width) / 2.f - bounds.left,
        y + 30.f
    );

    button.setPosition(
        x + (popupWidth - button.getSize().x) / 2.f,
        y + popupHeight - button.getSize().y - 20.f
    );
    auto btnBounds = buttonText.getLocalBounds();
    buttonText.setPosition(
        button.getPosition().x + (button.getSize().x - btnBounds.width) / 2.f - btnBounds.left,
        button.getPosition().y + (button.getSize().y - btnBounds.height) / 2.f - btnBounds.top
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

bool Popup::wasButtonClicked() const {
    return buttonClicked;
}