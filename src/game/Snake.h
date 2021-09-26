#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include <vector>

class  Snake {
private:

    int size = 1;
    const int blockSize = 16;
    std::vector<sf::Vector2i> snakeBody;
    sf::Color snakeColor = sf::Color::Red;
    

    std::vector<sf::Vertex> vertexArray;
    sf::Vector2i movementDir = sf::Vector2i(-1, 0);
    sf::Vector2f postition = sf::Vector2f(100, 100);

public:

    Snake();
    void setSize(int sz) {size = sz;};
    void setColor(const sf::Color &clr);
    void draw(sf::RenderWindow &win);
};
