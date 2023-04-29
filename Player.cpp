#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.cpp"

class Player : public Entity {
private:
    int width, height;

public:
    Player(int width, int height, int x, int y, int dx, int dy, sf::Color color) 
        : Entity(x, y, dx, dy, color) {
        this->width = width;
        this->height = height;
    }
    // Destructor
    ~Player() {
    }

    void draw(sf::RenderWindow& window) {
        // Create a rectangle shape with the player's width and height
        sf::RectangleShape shape(sf::Vector2f(width, height));
        shape.setFillColor(color);
        // Set the position of the rectangle shape to match the player's position
        shape.setPosition(x, y);
        // Draw the rectangle shape to the window
        window.draw(shape);
    }

       // Get the radius of the ball
    int getRadius() const {
        return radius;
    }

    // Add any other necessary public members here
};
