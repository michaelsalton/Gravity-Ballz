#include <SFML/Graphics.hpp>
#include <math.h>

class Ball {
private:
    int x, y; // Position of the ball
    int dx, dy; // Speed of the ball
    int radius; // Radius of the ball
    sf::Color color;

public:
    // Constructor for a ball with a color
    Ball(int x, int y, int dx, int dy, int radius, sf::Color color) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->radius = radius;
        this->color = color;
    }

    // Destructor
    ~Ball() {
    }

    // Move the ball by updating its position based on its speed
    void move() {
        x += dx;
        y += dy;
        const int gravity = 0.5;
        dy += gravity;
    }

    // Draw the ball on the screen using a graphics library
    void draw(sf::RenderWindow& window) {
        // Ball has a color
        sf::CircleShape shape(radius);
        shape.setFillColor(color);
        shape.setPosition(x, y);
        window.draw(shape);
    }

    // Get the radius of the ball
    int getRadius() const {
        return radius;
    }

    // Add any other necessary public members here
};
