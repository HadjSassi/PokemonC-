#include "gui/WelcomePage/WelcomePage.hpp"
#include <SFML/Graphics.hpp>


int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Pokemon The Game", sf::Style::Default);

    std::unique_ptr<BasePage> state = std::make_unique<WelcomePage>();

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (state) state->handleEvent(event);
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
