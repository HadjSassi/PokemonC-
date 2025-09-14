#include "BasePage.hpp"

BasePage::BasePage() {
    font_.loadFromFile("../resources/font/arial.ttf");
    text_.setFont(font_);
}

void BasePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::Text centered = text_;

    const auto bounds = centered.getLocalBounds();
    centered.setOrigin(bounds.left + bounds.width / 2.f,
                       bounds.top + bounds.height / 2.f);

    const sf::View &view = target.getView();
    centered.setPosition(view.getCenter());

    target.draw(centered, states);
}
