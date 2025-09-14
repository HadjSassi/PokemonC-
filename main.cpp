#include "gui/WelcomePage/WelcomePage.hpp"
#include "gui/HomePage/HomePage.hpp"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");

    WelcomePage welcomePage;
    HomePage mainPage;
    bool showWelcome = true;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        if (showWelcome) {
            welcomePage.update();
            window.draw(welcomePage);
            if (welcomePage.isTimeUp()) {
                showWelcome = false;
            }
        } else {
            mainPage.update();
            window.draw(mainPage);
        }

        window.display();
    }
    return 0;
}
