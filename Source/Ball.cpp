#include <SFML/Graphics.hpp>
#include <math.h>

class Ball{
private:
    // Texture
    sf::Texture texture;
    sf::Sprite sprite;
    
    // Movement
    int x;
    int y;
    int dx;
    int dy;

    // Attributes
    int scale; // Radius of the ball
    bool isEnemy;

    // Physics
    float grav = 0.5;

public:
    // Constructor for a ball with a color
    Ball(std::string texturePath, int x, int y, int dx, int dy, int scale, bool isEnemy) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->scale = scale;
        this->texture = texture;
        this->isEnemy = isEnemy;
        if (!texture.loadFromFile(texturePath)){
            std::cerr << "Error loading texture\n";
        }
        sprite.setTexture(texture);
        sprite.setScale(1,1);
    }
    // Destructor
    ~Ball() {
    }

    // Get the hitbox of the ball
    sf::IntRect hitbox(sf::RenderWindow& window) {
        sf::IntRect hitbox(x, y, scale, scale);
        //drawHitbox(window);
        return hitbox;
    }

    void drawHitbox(sf::RenderWindow& window) {
        sprite.setPosition(x,y);
        window.draw(sprite);
    }

    void draw(sf::RenderWindow &window) {
        gravity();
        sprite.setPosition(x,y);
        window.draw(sprite);
    }

    // Get the radius of the ball
    int getRadius() const {
        return scale;
    }

    bool enemy() {
        return isEnemy;
    }

    void gravity() {
        y += dy;
        dy += grav;
    }
};
