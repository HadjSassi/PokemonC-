#ifndef POKEMON_ENDINGPAGE_HPP
#define POKEMON_ENDINGPAGE_HPP
#include "../BasePage.hpp"
#include <SFML/Graphics.hpp>
#include "../components/VideoPlayer/VideoPlayer.hpp"

class EndingPage: public BasePage {
    public :
        EndingPage();

        bool isFinished() const override;

        void update() override;

        unique_ptr<BasePage> next() override;

        unique_ptr<BasePage> previous() override;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    sf::Clock clock_;
    std::unique_ptr<VideoPlayer> video_;
};


#endif //POKEMON_ENDINGPAGE_HPP