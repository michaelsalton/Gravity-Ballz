#include <math.h>

#include "../Headers/Entity.hpp"
#include "../Headers/Globals.hpp"

Entity::Entity(int x, int y, int dx, int dy, sf::Texture texture, bool isEnemy) {
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
    this->texture = texture;
    this->isEnemy = isEnemy;
}

Entity::~Entity() {
}

void Entity::moveUp() {
    y -= dy;
}
void Entity::moveDwon() {
    y += dy;
}
void Entity::moveLeft() {
    if (x >= 0)
        x -= dx;
}
void Entity::moveRight() {
    if (x+150 <= SCREEN_WIDTH)
        x += dx;
}

sf::Texture Entity::getTexture() {
    return texture;
}
