#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "config.h"
#include "game/Snake.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), "SFML works!");
    Snake snake;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        snake.draw(window);
        window.display();
    }

    return 0;
}
