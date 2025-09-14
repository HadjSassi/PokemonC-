#ifndef BASEPAGE_HPP
#define BASEPAGE_HPP

#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

class BasePage : public sf::Drawable {
public:
    BasePage();

    virtual void handleEvent(const sf::Event &) {
    }

    virtual bool isFinished() const { return false; }
    virtual unique_ptr<BasePage> next() { return nullptr; }

protected:
    sf::Text text_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
#endif // BASEPAGE_HPP
