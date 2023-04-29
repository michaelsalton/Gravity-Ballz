#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>

#include "Ball.cpp"
#include "Player.cpp"
#include "Themes.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1600), "Gravity Ballz ++");

    std::vector<Ball> balls; // Vector to hold the balls

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
        if (rand() % 10 == 0) {
            sf::Color color(rand() % 256, rand() % 256, rand() % 256); // Generate a random color
            Ball ball(rand() % 1200, 0, 0, rand() % 10 + 5, rand() % 20 + 10, color); // Generate a random ball
            balls.push_back(ball); // Add the ball to the vector
        }

        // Move and draw all the balls
        for (auto& ball : balls) {
            ball.move();
            ball.draw(window);
        }

        Player player(100, 50, 100, 100, 5, 5, red); // create a red Player object
        player.draw(window);

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
