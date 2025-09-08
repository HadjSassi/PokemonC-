#include <SFML/Graphics.hpp>

#include "headers/Pokemon.hpp"

int main() {

    Pokemon pokemon(1, "monster1", 100, 20, 10, 1);
    pokemon.displayInfo();

    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}
