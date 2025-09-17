#include "gui/WelcomePage/WelcomePage.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.hpp"
#include "entities/headers/PokemonAttack.hpp"
#include "gui/FightingPage/FightingPage.hpp"
#include "gui/HomePage/HomePage.hpp"
int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, WINDOW_TITLE, sf::Style::Default);
    sf::Music music;
    if (!music.openFromFile(MUSIC_PATH)) {
        return NOT_FOUND;
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
