#include <SFML/Graphics.hpp>
#include <math.h>

#include "../Headers/Entity.hpp"

class Physics{
private:
static const float GRAVITY;

public:
    // Constructor
    Physics() {

    }
    // Destructor
    ~Physics() {
    }

    friend class Entity;

    static void gravity(Entity& object) {
        if (object.getPosition().second < SCREEN_HEIGHT - 150) {
            object.dy += GRAVITY;
            object.y += object.dy;
        }
    }
};

const float Physics::GRAVITY = 0.5f;