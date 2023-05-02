#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {
protected:
    int x, y; // Position
    int dx, dy; // Velocity
    sf::Texture texture;
    bool isEnemy;

public:
    Entity(int x, int y, int dx, int dy, sf::Texture texture, bool isEnemy);
    ~Entity();

    void moveUp();
    void moveDwon();
    void moveLeft();
    void moveRight();
    sf::Texture getTexture();
};

#endif
