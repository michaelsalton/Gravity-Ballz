#include <SFML/Graphics.hpp>
#include <math.h>

class Entity {
protected:
    int x, y; // Position
    int dx, dy; // Velocity
    int xDimension, yDimension;
    sf::Color color;

public:
    Entity() {
        x = 400;
        y = 400;
        color = sf::Color::White;
    }
    Entity(int x, int y, int dx, int dy, int xDim, int yDim, sf::Color color) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->xDimension = xDim;
        this->yDimension = yDim;
        this->color = color;
    }
    // Destructor
    ~Entity() {
    }

    //COLLISIONS
    //Make Hitboxes
    sf::FloatRect hitBox() const {
        return sf::FloatRect(x - xDimension / 2, y - yDimension / 2, xDimension, yDimension);
    }
    //Check if hitboxes intersect using .intersects()
    bool collidesWith(const Entity& other) const {
        return hitBox().intersects(other.hitBox());
    }   
    //Physics (Newton's 3rd Law)
    void N3L(const Entity& other) {
        //If they intersect
        if(hitBox().intersects(other.hitBox())) {
            //if 
        }
    }

    //##########
};