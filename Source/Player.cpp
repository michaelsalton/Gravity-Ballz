#include <SFML/Graphics.hpp>
#include <math.h>

#include "../Headers/Entity.hpp"
#include "../Headers/Globals.hpp"

class Player : public Entity {
private:
    int width, height;
    int grav = 100;
    float jumpVelocity = 100;
    bool isJumping = false;
    bool isBottom = true;

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
        sf::IntRect hitbox(x+width/3, y+height*0.1, width*0.8, height*0.9);
        //drawHitbox(window);
        return hitbox;
    }

    void drawHitbox(sf::RenderWindow& window) {
        sf::RectangleShape rectangle(sf::Vector2f(width*0.8, height*0.9));
        rectangle.setPosition(x+width/3, y+height*0.1);
        rectangle.setFillColor(sf::Color::Red);
        window.draw(rectangle);
    }

    void draw(sf::RenderWindow& window) {
        sf::RectangleShape shape(sf::Vector2f(width, height));
        sf::Sprite sprite;
        sprite.setPosition(x, y);
        sprite.setTexture(texture);
        window.draw(sprite);
    }

    std::pair<int,int> getSize() {
        return std::make_pair(width, height);;
    }

    void keyboard() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (isBottom && !isJumping) {
                isJumping = true;
                isBottom = false;
                jump();
            }
        }
    }

    void gravity() {
        if (!isJumping) {
            y += grav;
        }
        if (y >= SCREEN_HEIGHT-playerHeight) {
            y = SCREEN_HEIGHT-playerHeight;
            isBottom = true;
        }
        if (y <= SCREEN_HEIGHT-playerHeight) {
            isJumping = false;
        }
    }
};
