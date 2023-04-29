#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>

#include "Ball.cpp"

// Allan is a nigga

// Allan is a legendary programmer

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1600), "Gravity Ballz ++");
    sf::CircleShape shape(100.f);
    sf::RectangleShape square(sf::Vector2f(300, 100));
    square.setPosition(400, 1400);
    square.setFillColor(sf::Color::Black);

    float x = 400;
    float y = 0;
    float dx = 0; // x velocity
    float dy = 0; // y velocity
    float g = 1; // dy^2
    float dampening = 0.8;

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
