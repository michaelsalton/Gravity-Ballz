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
        sf::RectangleShape shape(sf::Vector2f(width, height));
        shape.setFillColor(color);
        shape.setPosition(x, y);
        window.draw(shape);
    }

};
