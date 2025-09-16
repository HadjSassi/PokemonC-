#ifndef BASEPAGE_HPP
#define BASEPAGE_HPP

#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

class BasePage : public sf::Drawable {
public:
    BasePage();

    virtual void handleEvent(const sf::Event &, sf::Vector2u winSize) {}
    virtual void update() = 0;
    virtual bool isFinished() const { return false; }
    virtual unique_ptr<BasePage> next() { return nullptr; }
    virtual unique_ptr<BasePage> previous() { return nullptr; }
    virtual ~BasePage() = default;
protected:
    sf::Text text_;
    sf::Font font_;
    sf::Texture wallpaperTexture_;
    sf::Sprite wallpaperSprite_;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    bool isWallpaper ;
};
#endif // BASEPAGE_HPP
