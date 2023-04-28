#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.cpp"

class Player : public Entity {
private:
    int xDimension, yDimension;
    // Add any other necessary private members here

public:
    // Constructor
    Player(int xDimension, int yDimension) {
        Entity();
        xDimension = xDimension;
        yDimension = yDimension;
    }

    // Destructor
    ~Player() {
    }

    // Draw the rectangle on the screen using a graphics library
    void draw(sf::RenderWindow& window) {
        // Create a circle shape with the ball's radius
        sf::RectangleShape shape(xDimension, yDimension);
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
