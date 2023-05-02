#include <SFML/Graphics.hpp>
#include <math.h>

#include "../Headers/Entity.hpp"

class Player : public Entity {
private:
    int width, height;

public:
    Player(int width, int height, int x, int y, int dx, int dy, sf::Texture texture) 
        : Entity(x, y, dx, dy, texture, false) {
        this->width = width;
        this->height = height;
    }
    // Destructor
    ~Player() {
    }

    // Get the hitbox of the player
    sf::IntRect hitbox(sf::RenderWindow& window) {
        sf::IntRect hitbox(x, y, height, width);
        drawHitbox(window);
        return hitbox;
    }

    void drawHitbox(sf::RenderWindow& window) {
        sf::RectangleShape rectangle(sf::Vector2f(height, width));
        rectangle.setPosition(x, y);
        rectangle.setFillColor(sf::Color::Red);
        window.draw(rectangle);
    }

    void draw(sf::RenderWindow& window) {
        sf::RectangleShape shape(sf::Vector2f(width, height));
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        window.draw(sprite);
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
