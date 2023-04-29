#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.cpp"

class Ball {
private:
    int x, y; // Position of the ball
    int xVelocity = 0, yVelocity = 0; // Speed of the ball
    int radius; // Radius of the ball
    sf::Color color;
    // Add any other necessary private members here

public:
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
    // rework this to be: moveHorizontal() and moveVertical()
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

    // Add any other necessary public members here
};
