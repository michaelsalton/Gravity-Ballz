#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 500), "Gravity Ballz ++");
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
    
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update position
        dy += g;
        x += dx;
        y += dy;
        
        // Check boundaries and reverse direction if necessary
        if (x + 2 * shape.getRadius() > window.getSize().x) {
            dx = -dx;
            x = window.getSize().x - 2 * shape.getRadius();
        }
        if (y + 2 * shape.getRadius() > window.getSize().y) {
            dy = -dampening * dy; // reduce magnitude of y-velocity
            y = window.getSize().y - 2 * shape.getRadius(); // prevent ball from going below the bottom of the window
        }

        // Set background colour
        window.clear(sf::Color(230, 196, 147));

        // Draw circle and display window
        shape.setPosition(x, y);
        window.draw(shape);
        window.draw(square);
        window.display();

        // Wait for 1/60th of a second (60 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
