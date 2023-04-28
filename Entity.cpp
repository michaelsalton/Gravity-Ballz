#include <SFML/Graphics.hpp>
#include <math.h>

class Entity {
private:
    int x, y; // Position
    int xVelocity, yVelocity; // Velocity
    sf::Color color;
    // Add any other necessary private members here

public:
    // Constructor
    Entity() {
        
    }
    Entity(int startX, int startY, int startSpeedX, int startSpeedY, int startRadius, sf::Color color) {
        x = startX;
        y = startY;
        xVelocity = startSpeedX;
        yVelocity = startSpeedY;
        color = color;
    }

    // Destructor
    ~Entity() {
    }

    // Move by updating its position based on its speed
    void move() {
        x += xVelocity;
        y += yVelocity;

        // Simulate gravity by increasing the ball's y velocity
        // You can adjust the gravity constant as needed
        const int gravity = 1;
        yVelocity += gravity;
    }

    // Add any other necessary public members here
};
