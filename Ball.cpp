#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.cpp"

class Ball : public Entity {
private:
    int x, y; // Position of the ball
    int xVelocity, yVelocity; // Speed of the ball
    int radius = xDimension/2; // Radius of the ball
    
    // Add any other necessary private members here

public:
    sf::Color color;
    // Constructor
    Ball(int startX, int startY, int startSpeedX, int startSpeedY, int startRadius, sf::Color color) {
        x = startX;
        y = startY;
        xVelocity = startSpeedX;
        yVelocity = startSpeedY;
        radius = startRadius;
        color = color;
    }

    // Destructor
    ~Ball() {
    }

    // Move the ball by updating its position based on its speed
    void moveLeft() {
        xVelocity = 5;
        x -= xVelocity;
    }
    void moveRight() {
        xVelocity = 5;
        x += xVelocity;
    }
    void moveUp() {
        yVelocity = 5;
        y -= yVelocity;
    }
    void moveDown() {
        yVelocity = 5;
        y += yVelocity;
    }
    int getX() {return x;} int getY() {return y;}

    // Draw the ball on the screen using a graphics library
    void draw(sf::RenderWindow& window) {
        // Create a circle shape with the ball's radius
        sf::CircleShape shape(radius);
        shape.setFillColor(color);
        // Set the position of the circle shape to match the ball's position
        shape.setPosition(x, y);
        // Draw the circle shape to the window
        window.draw(shape);
    }

    // Get the radius of the ball
    int getRadius() const {
        return radius;
    }
    bool collidesWith(const Ball& other) const {
        // Find distance between centers of the two balls
        float distX = x - other.x;
        float distY = y - other.y;
        float distance = sqrt(distX * distX + distY * distY);

        // Check if the distance is less than or equal to the sum of the radii
        return distance <= radius + other.radius;
    }
    int setX(int x) {
        this->x = x;
    }
    int setY(int y) {
        this->y = y;
    }
    int setDX(int dxx) {
        this->xVelocity = dxx;
        dx = dxx;
    }
    int setDY(int dyy) {
        this->yVelocity = dyy;
        dy = dyy;
    }
    // Add any other necessary public members here
};
