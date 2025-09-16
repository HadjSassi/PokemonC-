#include "gui/WelcomePage/WelcomePage.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "entities/headers/PokemonAttack.hpp"
#include "gui/FightingPage/FightingPage.hpp"
#include "gui/HomePage/HomePage.hpp"
int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Pokemon The Game", sf::Style::Default);
    sf::Music music;
    if (!music.openFromFile("../resources/music/son.mp3")) {
        return -1;
    }
    music.setLoop(true);
    music.play();
    std::unique_ptr<BasePage> state = std::make_unique<WelcomePage>();
    // std::unique_ptr<BasePage> state = std::make_unique<HomePage>();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (state) state->handleEvent(event, window.getSize());
        }

        if (state) state->update();

        if (state && state->isFinished()) {
            auto next = state->next();
            if (next) state = std::move(next);
        }

        window.clear();
        if (state) window.draw(*state);
        window.display();
    }
    return 0;
}
