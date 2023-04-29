#include <SFML/Graphics.hpp>
#include <math.h>
#include "Globals.hpp"

class Entity {
protected:
    int x, y; // Position
    int dx, dy; // Velocity
    sf::Color color;

public:
    Entity(int x, int y, int dx, int dy, sf::Color color) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->color = color;
    }
    // Destructor
    ~Entity() {
    }

    void moveUp() {
        y -= dy;
    }
    void moveDwon() {
        y += dy;
    }
    void moveLeft() {
        if (x >= 0)
            x -= dx;
    }
    void moveRight() {
        if (x+150 <= SCREEN_WIDTH)
            x += dx;
    }
};


