#ifndef WELCOMEPAGE_HPP
#define WELCOMEPAGE_HPP
#include "../BasePage.hpp"
#include <SFML/Graphics.hpp>
#include "../VideoPlayer/VideoPlayer.hpp"
#include "../../entities/headers/PokemonParty.hpp"

class WelcomePage : public BasePage {
public:
    WelcomePage();

    bool isFinished() const override;

    void update() override;

    unique_ptr<BasePage> next() override;

    unique_ptr<BasePage> previous() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Clock clock_;
    std::unique_ptr<VideoPlayer> video_;
};
#endif // WELCOMEPAGE_HPP
