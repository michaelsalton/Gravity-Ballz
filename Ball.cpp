#include <math.h>

class Ball {
private:
    int x, y; // Position of the ball
    int xVelocity, yVelocity; // Speed of the ball
    int radius; // Radius of the ball
    // Add any other necessary private members here

public:
    // Constructor
    Ball(int startX, int startY, int startSpeedX, int startSpeedY, int startRadius) {
        x = startX;
        y = startY;
        xVelocity = startSpeedX;
        yVelocity = startSpeedY;
        radius = startRadius;
    }

    // Destructor
    ~Ball() {
    }

    // Move the ball by updating its position based on its speed
    void move() {
        x += xVelocity;
        y += yVelocity;
    }

    // Draw the ball on the screen using a graphics library
    void draw() {
        // Add code here to draw the ball using a graphics library
    }

    // Check for collisions with another ball
    bool checkCollision(Ball otherBall) {
        int distance = sqrt(pow(x - otherBall.x, 2) + pow(y - otherBall.y, 2));
        if (distance <= radius + otherBall.radius) {
            return true;
        }
        return false;
    }

    // Add any other necessary public members here
};
