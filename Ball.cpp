#include <SFML/Graphics.hpp>
#include <math.h>

class Ball {
private:
    int x, y; // Position of the ball
    int xVelocity, yVelocity; // Speed of the ball
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
    void move() {
        x += xVelocity;
        y += yVelocity;

        // Simulate gravity by increasing the ball's y velocity
        // You can adjust the gravity constant as needed
        const int gravity = 1;
        yVelocity += gravity;
    }

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
