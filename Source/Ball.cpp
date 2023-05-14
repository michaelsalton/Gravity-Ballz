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
    
    // Movement
    int x;
    int y;
    int dy = 0;

    // Attributes
    bool isEnemy;

    // Physics
    float grav;

public:
    // Constructor for a ball with a color
    Ball(std::string texturePath, int x, int y, int grav, bool isEnemy) {
        this->x = x;
        this->y = y;
        this->grav = grav;
        this->texturePath = texturePath;
        this->isEnemy = isEnemy;

        if (!texture.loadFromFile(texturePath)){
            std::cerr << "Error loading texture\n";
        }
        sprite.setTexture(texture);
        sprite.setScale(1,1);
    }

    void draw(sf::RenderWindow &window) {
        gravity();
        sprite.setPosition(x,y);
        window.draw(sprite);
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
        return sprite.getGlobalBounds();
    }

    bool enemy() {
        return isEnemy;
    }

    void gravity() {
        dy += grav;
        y += dy;
    }
};
