#include "BasePage.hpp"
#include "../config.hpp"

BasePage::BasePage() {
    font_.loadFromFile(FONT_PATH);
    text_.setFont(font_);
    wallpaperTexture_.loadFromFile(WALLPAPER_PATH);
    wallpaperSprite_.setTexture(wallpaperTexture_);
    isWallpaper = true;
}

void BasePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (isWallpaper) target.draw(wallpaperSprite_, states);
    sf::Text centered = text_;

    const auto bounds = centered.getLocalBounds();
    centered.setOrigin(bounds.left + bounds.width / LINE_THICKNESS,
                       bounds.top + bounds.height / LINE_THICKNESS);

    const sf::View &view = target.getView();
    centered.setPosition(view.getCenter());

    target.draw(centered, states);
}
