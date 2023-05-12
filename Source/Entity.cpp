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

float grav = 0.5;
float playergGrav = 100;

Entity::~Entity() {
}

void Entity::moveLeft() {
    if (x >= 0)
        x -= dx;
}
void Entity::moveRight() {
    if (x+playerWidth <= SCREEN_WIDTH)
        x += dx;
}
void Entity::jump() {
    // velocity is decreasing as you go up
    // velocity before hit ground is same as launch velcotiy
    // velcotiy at top is 0
    if (y+playerHeight == SCREEN_HEIGHT)
        y -= playergGrav;
    //dy -= grav;
}
void Entity::gravity() {
    y += dy;
    dy += grav;
}
sf::Texture Entity::getTexture() {
    return texture;
}
std::pair<int,int> Entity::getPosition() {
    return std::make_pair(x, y);;
}