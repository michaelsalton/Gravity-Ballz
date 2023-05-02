#include <SFML/Graphics.hpp>
#include <math.h>

#include "../Headers/Entity.hpp"

class Ball : public Entity{
private:
    int radius; // Radius of the ball

public:
    // Constructor for a ball with a color
    Ball(int x, int y, int dx, int dy, int radius, sf::Texture texture, bool isEnemy)
        : Entity(x, y, dx, dy, texture, isEnemy) {
        this->radius = radius/5;
    }
    // Destructor
    ~Ball() {
    }

    // Get the hitbox of the ball
    sf::IntRect hitbox(sf::RenderWindow& window) {
        sf::IntRect hitbox(x - radius, y - radius, radius * 2, radius * 2);
        drawHitbox(window);
        return hitbox;
    }

    void drawHitbox(sf::RenderWindow& window) {
        sf::RectangleShape rectangle(sf::Vector2f(radius * 2, radius * 2));
        rectangle.setPosition(x - radius, y - radius);
        rectangle.setFillColor(sf::Color::Red);
        window.draw(rectangle);
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
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setScale(radius, radius);
        window.draw(sprite);
    }

    // Get the radius of the ball
    int getRadius() const {
        return radius;
    }

    bool enemy() {
        return isEnemy;
    }

    // Add any other necessary public members here
};
