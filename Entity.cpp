#include <SFML/Graphics.hpp>
#include <math.h>

class Entity {
private:
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

    // Move by updating its position based on its speed
    void move() {
        x += dx;
        y += dy;

        // Simulate gravity by increasing the ball's y velocity
        // You can adjust the gravity constant as needed
        const int gravity = 1;
        dy += gravity;
    }

    // Add any other necessary public members here
};


