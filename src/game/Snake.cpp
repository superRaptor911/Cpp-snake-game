#include "Snake.h"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include <cmath>
#include <vector>

Snake::Snake() {
    snakeBody.push_back(sf::Vector2f(100, 100));
    snakeBody.push_back(sf::Vector2f(100 + blockSize, 100));

    for (int i = 0; i < snakeBody.size() ; i++) {
        sf::Vector2f pos = snakeBody[i];

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

void Snake::increaseSize() {
    int size = snakeBody.size();
    sf::Vector2f dir = snakeBody[size - 2 ] - snakeBody[size - 1 ];
    sf::Vector2f newBlockPos = snakeBody[size - 1] + dir * -1.f;
    snakeBody.push_back(newBlockPos);

    sf::Vector2f pos = newBlockPos;

    // Add Vertex
    vertexArray.push_back(sf::Vertex(pos, snakeColor));

    pos.x += blockSize;
    vertexArray.push_back(sf::Vertex(pos, snakeColor));

    pos.y += blockSize;
    vertexArray.push_back(sf::Vertex(pos, snakeColor));

    pos.x -= blockSize;
    vertexArray.push_back(sf::Vertex(pos, snakeColor));
}

void Snake::run(float delta) {
    auto movVect = movementDir * speed * delta;
    distanceCovered += movVect;
    
    bool anyChange = false;

    sf::Vector2f oldPos = snakeBody[0];

    if (std::fabs(distanceCovered.x) > blockSize) {
        anyChange = true;
        snakeBody[0].x += distanceCovered.x;
        distanceCovered = sf::Vector2f(0, 0);
    }
    else if (std::fabs(distanceCovered.y) > blockSize) {
        anyChange = true;
        snakeBody[0].y += distanceCovered.y;
        distanceCovered = sf::Vector2f(0, 0);
    }

    if (!anyChange) {
        return;
    }

    for (int i = 1; i < snakeBody.size(); i++) {
        auto temp = snakeBody[i];
        snakeBody[i] = oldPos;
        oldPos = temp;
    }

    for (int i = 0; i < snakeBody.size() ; i++) {
        sf::Vector2f pos = snakeBody[i];
        int j = i * 4;

        vertexArray[j].position = pos;

        pos.x += blockSize;
        vertexArray[j + 1].position = pos;

        pos.y += blockSize;
        vertexArray[j + 2].position = pos;

        pos.x -= blockSize;
        vertexArray[j + 3].position = pos;
    }
}
