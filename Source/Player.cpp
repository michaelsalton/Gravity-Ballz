#include <SFML/Graphics.hpp>
#include "../Headers/Globals.hpp"
#include <iostream>
#include <string>

class Player {
private:
    // Texture
    std::string texturePath;
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

    // State
    std::string anim_state = "idle";
    std::vector<sf::IntRect> anim_idle;

public:
    Player(std::string texturePath, float x, float speed, float jumpHeight) {
        this->x = x;
        this->y = 0;
        this->speed = speed;
        this->jumpHeight = jumpHeight;
        this->texturePath = texturePath;

        if (!texture.loadFromFile(texturePath)){
            std::cerr << "Error loading texture\n";
        }
        sprite.setTexture(texture);
        sprite.setScale(1.5,1.5);

        // Idle
        anim_idle.push_back(sf::IntRect(0, 3, 51, 67)); // 
        anim_idle.push_back(sf::IntRect(51, 2, 51, 68)); //
        anim_idle.push_back(sf::IntRect(102, 0, 51, 70)); //
        anim_idle.push_back(sf::IntRect(153, 1, 51, 69)); //
        anim_idle.push_back(sf::IntRect(204, 2, 51, 68)); //
    }

    void draw(sf::RenderWindow &window) {
        animMachine();
        gravity();
        sprite.setPosition(x,y);
        window.draw(sprite);
    }

    void animMachine() {
        static int frameIndex_idle = 0; // Variable to keep track of the current frame index
        static sf::Clock clock; // Clock to measure the elapsed time
        
        // Check if 2 seconds have elapsed since the last frame change
        if (clock.getElapsedTime().asSeconds() >= 0.1) {
            // Set the texture rect based on the current frame index

            // Update the frame index

            if (anim_state == "idle" && !isJumping) {
                sprite.setTextureRect(anim_idle[frameIndex_idle]);
            }

            if (frameIndex_idle < anim_idle.size()) {
                frameIndex_idle = 0;
            }

            frameIndex_idle++;
            
            // Restart the clock to measure the elapsed time for the next frame change
            clock.restart();
        }
    }

    // Get the hitbox of the player
    sf::IntRect hitbox(sf::RenderWindow& window) {
        sf::IntRect hitbox(x, y, getSize().width, getSize().height);
        //drawHitbox(window, hitbox);
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
        if (!isJumping) {
            if (y < playerBottom()) {
                dy -= grav;
                y -= dy;
            }
            else if (y > playerBottom()) {
                y = playerBottom();
                onGround = true;
                isJumping = false;
                dy = 0;
            }
        } else if (isJumping) {
            if (y > SCREEN_HEIGHT - jumpHeight) {
                dy = jumpSpeed;
                dy -= grav;
                y -= dy;
            } else if (y <= SCREEN_HEIGHT - jumpHeight) {
                isJumping = false;
                dy = 0;
            }
        }
    }
};
