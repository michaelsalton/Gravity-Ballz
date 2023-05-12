#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {
protected:
    int x, y; // Position
    int dx, dy; // Velocity
    sf::Texture texture;
    bool isEnemy;
    float jumpVelocity = 40;
    bool isJumping = false;
    bool isBottom = true;

public:
    Entity(int x, int y, int dx, int dy, sf::Texture texture, bool isEnemy);
    ~Entity();

    friend class Physics;

    void moveLeft();
    void moveRight();
    void jump();
    void gravity();
    sf::Texture getTexture();
    std::pair<int,int> getPosition();
};

#endif
