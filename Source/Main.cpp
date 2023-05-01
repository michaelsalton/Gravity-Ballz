#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "Ball.cpp"
#include "Player.cpp"
#include "Score.cpp"
#include "../Headers/Themes.hpp"
#include "../Headers/Globals.hpp"

int randomNum(int min, int max) {
    int shift = min;
    int range = max-min+1;
    int rum = rand() % range + shift;
    return rum;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Gravity Ballz ++");

    std::vector<Ball> balls; // Vector to hold the balls

    // Fonts
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\alaan\\Documents\\Projects\\Gravity-Ballz\\Media\\Fonts\\caviar\\Caviar_Dreams_Bold.ttf")) {
        // error handling
    }

    Score score(
        SCREEN_WIDTH - 100,
        50,
        0,
        font
    ); // Create a Score object

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

        // Check if it's time to create a new ball
        if (rand() % 50 == 0) {
            sf::Color color(rand() % 256, rand() % 256, rand() % 256); // Generate a random color
            Ball ball(
                randomNum(30, SCREEN_WIDTH - 30), // X Coordinate
                -50,                  // Y Coordinate
                0,                  // X Velocity
                rand() % 10 + 5,    // Y Velocity
                rand() % 20 + 10,   // Radius
                color               // Color
            );
            balls.push_back(ball); // Add the ball to the vector
        }

        // Move and draw all the balls
        for (auto it = balls.begin(); it != balls.end(); /*no increment here*/) {
            Ball& ball = *it;
            ball.gravity();
            ball.draw(window);
            if (player.hitbox().intersects(ball.hitbox())) {
                it = balls.erase(it);
                score.increment();
            } else {
                ++it; // increment here
            }
        }

        score.draw(window);
        player.draw(window);
        player.keyboard();

        // Display the window
        window.display();
        // Set background colour
        window.clear(sf::Color(230, 196, 147));
        // Wait for 1/60th of a second (60 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
