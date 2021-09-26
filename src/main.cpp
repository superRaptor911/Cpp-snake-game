#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"
#include "config.h"
#include "game/SnakePlayer.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WIN_X, WIN_Y), "SFML works!");
    SnakePlayer snake;
    sf::Clock clock;
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    snake.increaseSize();
    while (window.isOpen()) {
        float elapsed = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        snake.run(elapsed);
        snake.draw(window);
        window.display();
    }

    return 0;
}
