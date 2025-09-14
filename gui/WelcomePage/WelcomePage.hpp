//
// Created by mahdihadjsassi on 12/09/2025.
//
#ifndef WELCOMEPAGE_HPP
#define WELCOMEPAGE_HPP
#include "../BasePage.hpp"
#include <SFML/Graphics.hpp>

class WelcomePage : public BasePage {
public:
    WelcomePage();
    bool isTimeUp() const;
    void update() override;
private:
    sf::Clock clock_;
};
#endif // WELCOMEPAGE_HPP
