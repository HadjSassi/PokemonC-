
#ifndef WELCOMEPAGE_HPP
#define WELCOMEPAGE_HPP
#include "../BasePage.hpp"
#include <SFML/Graphics.hpp>

class WelcomePage : public BasePage {

private:
    sf::Clock clock_;

public:
    WelcomePage();
    bool isFinished() const override;
    std::unique_ptr<BasePage> next() override;

};
#endif // WELCOMEPAGE_HPP
