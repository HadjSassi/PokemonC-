#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP
#include "../BasePage.hpp"

class HomePage : public BasePage {

private:
    sf::RectangleShape playButton_;
    sf::Text playText_;
    bool clicked_ = false;
    mutable sf::FloatRect buttonBounds_{};
    void layoutButton();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    HomePage();
    void handleEvent(const sf::Event& event) override;
    bool isFinished() const override;
    std::unique_ptr<BasePage> next() override;

};
#endif // HOMEPAGE_HPP
