#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {
protected:
    int x, y; // Position
    int dx, dy; // Velocity
    sf::Color color;

public:
    Entity(int x, int y, int dx, int dy, sf::Color color);
    ~Entity();

    void moveUp();
    void moveDwon();
    void moveLeft();
    void moveRight();
};

#endif
