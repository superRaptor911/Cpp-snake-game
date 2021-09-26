#include "Snake.h"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include <vector>

Snake::Snake() {
    sf::Vector2f pos = postition;
    for (int i = 0; i < size ; i++) {
        vertexArray.push_back(sf::Vertex(pos, snakeColor));

        pos.x += blockSize;
        vertexArray.push_back(sf::Vertex(pos, snakeColor));

        pos.y += blockSize;
        vertexArray.push_back(sf::Vertex(pos, snakeColor));

        pos.x -= blockSize;
        vertexArray.push_back(sf::Vertex(pos, snakeColor));
    }
}

void Snake::setColor(const sf::Color &clr) {
    snakeColor = clr;
}


void Snake::draw(sf::RenderWindow &win) {
    win.draw(&vertexArray[0], vertexArray.size(), sf::Quads);
}

