#include <SFML/Graphics.hpp>
#include <math.h>

#include "../Headers/Entity.hpp"

class Ball : public Entity{
private:
    int scale; // Radius of the ball

public:
    // Constructor for a ball with a color
    Ball(int x, int y, int dx, int dy, int scale, sf::Texture texture, bool isEnemy)
        : Entity(x, y, dx, dy, texture, isEnemy) {
        this->scale = scale;
    }
    // Destructor
    ~Ball() {
    }

    // Get the hitbox of the ball
    sf::IntRect hitbox(sf::RenderWindow& window) {
        sf::IntRect hitbox(x, y, scale*30, scale*30);
        //drawHitbox(window);
        return hitbox;
    }

    void drawHitbox(sf::RenderWindow& window) {
        sf::RectangleShape rectangle(sf::Vector2f(scale*30, scale*30));
        rectangle.setPosition(x, y);
        rectangle.setFillColor(sf::Color::Red);
        window.draw(rectangle);
    }

    // Draw the ball on the screen using a graphics library
    void draw(sf::RenderWindow& window) {
        // Ball has a color
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setScale(scale, scale);
        window.draw(sprite);
    }

    // Get the radius of the ball
    int getRadius() const {
        return scale;
    }

    bool enemy() {
        return isEnemy;
    }

    // Add any other necessary public members here
};
