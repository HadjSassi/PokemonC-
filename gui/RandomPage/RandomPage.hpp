#ifndef RANDOMPAGE_HPP
#define RANDOMPAGE_HPP

#include "../BasePage.hpp"
#include <random>

class RandomPage : public BasePage {
public:
    RandomPage();

    bool isFinished() const override;

    unique_ptr<BasePage> next() override;

private:
    sf::Clock clock_;
    int value_ = 0;
};
#endif // RANDOMPAGE_HPP
