#ifndef RANDOMPAGE_HPP
#define RANDOMPAGE_HPP

#include "../BasePage.hpp"
#include "../VideoPlayer/VideoPlayer.hpp"
#include <random>

class RandomPage : public BasePage {
public:
    RandomPage();

    bool isFinished() const override;

    unique_ptr<BasePage> next() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void update() override;

private:
    sf::Clock clock_;
    std::unique_ptr<VideoPlayer> video_;
    int value_ = 0;
};
#endif // RANDOMPAGE_HPP
