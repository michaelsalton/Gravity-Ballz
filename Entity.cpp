#include <SFML/Graphics.hpp>
#include <math.h>

class Entity {
protected:
    int x, y; // Position
    int dx, dy; // Velocity
    sf::Color color;

public:
    Entity(int x, int y, int dx, int dy, sf::Color color) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
        this->color = color;
    }
    // Destructor
    ~Entity() {
    }
};


