#include <SFML/Graphics.hpp>
#include "../Headers/Globals.hpp"
#include <iostream>

class Player {
private:
    // Texture
    sf::Texture texture;
    sf::Sprite sprite;

    // Movement
    float x;
    float y;
    float speed;
    float jumpHeight;

    // Physics
    float grav = 1;
    float dy = 0;
    bool isJumping = false;
    bool onGround = false;
    float jumpSpeed = 20;

public:
    Player();
    Player(std::string texturePath, float x, float speed, float jumpHeight) {
        this->x = x;
        this->y = 0;
        this->speed = speed;
        this->jumpHeight = jumpHeight;
        if (!texture.loadFromFile(texturePath)){
            std::cerr << "Error loading texture\n";
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(39, 56, 52, 72));
        sprite.setScale(1.5,1.5);
    }

    void draw(sf::RenderWindow &window) {
        gravity();
        sprite.setPosition(x,y);
        window.draw(sprite);
    }

    // Get the hitbox of the player
    sf::IntRect hitbox(sf::RenderWindow& window) {
        sf::IntRect hitbox(x, y, getSize().width, getSize().height);
        drawHitbox(window, hitbox);
        return hitbox;
    }

    void drawHitbox(sf::RenderWindow& window, sf::IntRect hitbox) {
        sf::RectangleShape rectangle(sf::Vector2f(hitbox.width, hitbox.height));
        rectangle.setPosition(hitbox.left, hitbox.top);
        rectangle.setFillColor(sf::Color::Red);
        window.draw(rectangle);
    }

    sf::FloatRect getSize() {
        return sprite.getGlobalBounds();
    }

    float playerBottom() {
        return SCREEN_HEIGHT - getSize().height;
    }

    void moveLeft() {
        if (x >= 0) {
            x -= speed;
        }
    }

    void moveRight() {
        if (x + getSize().width <= SCREEN_WIDTH) {
            x += speed;
        }
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
            if (onGround && !isJumping) {
                isJumping = true;
                onGround = false;
            }
        }
    }

    void gravity() {
        //std::cout << "Y: " << y << " Bottom: " << getPlayerBottom() << std::endl;
        if (!isJumping) {
            if (y < playerBottom()) {
                y -= dy;
                dy -= grav;
            }
            else if (!onGround) {
                y = playerBottom();
                onGround = true;
                isJumping = false;
                dy = 0;
            }
        }
        else if (isJumping) {
            if (y > SCREEN_HEIGHT - jumpHeight) {
                y -= dy;
                dy = jumpSpeed;
                dy -= grav;
            }
            else if (y <= SCREEN_HEIGHT - jumpHeight) {
                isJumping = false;
                dy = 0;
            }
        }
    }
};