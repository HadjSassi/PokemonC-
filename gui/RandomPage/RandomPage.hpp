
#ifndef RANDOMPAGE_HPP
#define RANDOMPAGE_HPP

#include "../BasePage.hpp"
#include <random>

class RandomPage : public BasePage {
private:
    sf::Clock clock_;
    int value_ = 0;

public:
    RandomPage();

    bool isFinished() const override;
    std::unique_ptr<BasePage> next() override;

};
#endif // RANDOMPAGE_HPP