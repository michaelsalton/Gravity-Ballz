#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "Ball.cpp"
#include "Player.cpp"
#include "Themes.hpp"
#include "Globals.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Gravity Ballz ++");

    std::vector<Ball> balls; // Vector to hold the balls

    Player player(
        150, // Width
        50, // Height
        SCREEN_WIDTH / 3, // X Position
        SCREEN_HEIGHT - SCREEN_HEIGHT * 0.1, // Y Position
        12, // X Velocity
        0, // Y Velocity
        green // Colour
    );

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ************** CODE HERE **************

        // Check if it's time to create a new ball
        if (rand() % 50 == 0) {
            sf::Color color(rand() % 256, rand() % 256, rand() % 256); // Generate a random color
            Ball ball(rand() % 1200, 0, 0, rand() % 10 + 5, rand() % 20 + 10, color); // Generate a random ball
            balls.push_back(ball); // Add the ball to the vector
        }

        // Move and draw all the balls
        for (auto it = balls.begin(); it != balls.end(); /*no increment here*/) {
            Ball& ball = *it;
            ball.gravity();
            ball.draw(window);
            if (player.hitbox().intersects(ball.hitbox())) {
                // delete ball here
                it = balls.erase(it); // erase() returns the iterator to the next element after the erased one
            } else {
                ++it; // increment here
            }
        }

        player.draw(window);

        player.keyboard();

        // ***************************************

        // Display the window
        window.display();
        // Set background colour
        window.clear(sf::Color(230, 196, 147));
        // Wait for 1/60th of a second (60 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
