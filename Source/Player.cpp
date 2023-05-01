#include <SFML/Graphics.hpp>
#include <math.h>

#include "../Headers/Entity.hpp"

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

    // Get the hitbox of the player
    sf::IntRect hitbox() {
        sf::IntRect hitbox(x, y, width, height);
        return hitbox;
    }

    void draw(sf::RenderWindow& window) {
        sf::RectangleShape shape(sf::Vector2f(width, height));
        shape.setFillColor(color);
        shape.setPosition(x, y);
        window.draw(shape);
    }

    void keyboard() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            moveRight();
        }
    }
};
