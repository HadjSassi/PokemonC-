#ifndef BASEPAGE_HPP
#define BASEPAGE_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class BasePage : public sf::Drawable {

protected:
    sf::Text text_;
    sf::Font font_;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    BasePage();
    virtual void handleEvent(const sf::Event&){}
    virtual bool isFinished() const { return false; }
    virtual std::unique_ptr<BasePage> next() { return nullptr; }
};
#endif // BASEPAGE_HPP
