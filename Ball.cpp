#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.hpp"

class Ball : public Entity{
private:
    int radius; // Radius of the ball

public:
    // Constructor for a ball with a color
    Ball(int x, int y, int dx, int dy, int radius, sf::Color color)
        : Entity(x, y, dx, dy, color) {
        this->radius = radius;
    }

    // Destructor
    ~Ball() {
    }

    // Move the ball by updating its position based on its speed
    void gravity() {
        x += dx;
        y += dy;
        const float gravity = 0.25;
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
