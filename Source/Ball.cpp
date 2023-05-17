#include <SFML/Graphics.hpp>
#include "../Headers/Globals.hpp"
#include <math.h>
#include <iostream>
#include <string>

class Ball{
private:
    // Texture
    std::string texturePath;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::CircleShape shape;
    int scale;
    sf::Color color;
    
    // Movement
    int x;
    int y;
    float dy = 0;

    // Attributes
    bool isEnemy;

    // Physics
    float grav;

public:
    // Constructor for a ball with a color
    Ball(std::string texturePath, int x, int y, float grav, bool isEnemy, int scale) {
        this->x = x;
        this->y = y;
        this->grav = grav;
        this->texturePath = texturePath;
        this->isEnemy = isEnemy;
        this->scale = scale;

        if (!texture.loadFromFile(texturePath)){
            std::cerr << "Error loading texture\n";
        }
        sprite.setTexture(texture);
        sprite.setScale(scale,scale);
    }
    Ball(sf::Color color, int x, int y, float grav, bool isEnemy, int scale) {
        this->x = x;
        this->y = y;
        this->grav = grav;
        this->color = color;
        this->isEnemy = isEnemy;
        this->scale = scale;

        shape.setFillColor(color);
        shape.setRadius(scale);
    }

    void draw(sf::RenderWindow &window) {
        gravity();
        shape.setPosition(x,y);
        window.draw(shape);
    }

    // Get the hitbox of the ball
    sf::IntRect hitbox(sf::RenderWindow& window) {
        sf::IntRect hitbox(x, y, getSize().width, getSize().height);
        //drawHitbox(window, hitbox);
        return hitbox;
    }

/*     void drawHitbox(sf::RenderWindow& window) {
        sprite.setPosition(x,y);
        window.draw(sprite);
    } */

    sf::FloatRect getSize() {
        return shape.getGlobalBounds();
    }

    bool enemy() {
        return isEnemy;
    }

    void gravity() {
        dy += grav;
        y += dy;
    }
};
