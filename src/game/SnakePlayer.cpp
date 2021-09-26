#include "SnakePlayer.h"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"


void SnakePlayer::run(float delta) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movementDir = sf::Vector2f(0, -1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movementDir = sf::Vector2f(0, 1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movementDir = sf::Vector2f(-1, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movementDir = sf::Vector2f(1, 0);
    }

    Snake::run(delta);
}
