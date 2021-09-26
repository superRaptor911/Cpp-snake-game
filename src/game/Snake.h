#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include <vector>

class  Snake {
protected:
    const int blockSize = 16;
    std::vector<sf::Vector2f> snakeBody;
    sf::Color snakeColor = sf::Color::Red;
    

    std::vector<sf::Vertex> vertexArray;
    sf::Vector2f movementDir = sf::Vector2f(-1, 0);
    float speed = 16.f;
    sf::Vector2f distanceCovered = sf::Vector2f(0, 0);

public:

    Snake();
    void setColor(const sf::Color &clr);
    void increaseSize();
    virtual void run(float delta);
    virtual void draw(sf::RenderWindow &win);
};
