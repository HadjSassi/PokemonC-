#ifndef WELCOMEPAGE_HPP
#define WELCOMEPAGE_HPP
#include "../BasePage.hpp"
#include <SFML/Graphics.hpp>

class WelcomePage : public BasePage {
public:
    WelcomePage();

    bool isFinished() const override;
    void update() override;
    unique_ptr<BasePage> next() override;

private:
    sf::Clock clock_;
};
#endif // WELCOMEPAGE_HPP
