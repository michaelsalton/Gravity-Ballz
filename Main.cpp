// SFML stuff
#include <SFML/Graphics.hpp>

// Normal stuff
#include <chrono>
#include <thread>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Gravity Ballz ++");
    sf::CircleShape shape(100.f);
    float x = 400;
    float y = 000;
    float dx = 0; // x velocity
    float dy = 0; // y velocity
    float g = 1; // dy^2
    
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update position
        x += dx;
        y += dy;
        dy += g;
        
        // Check boundaries and reverse direction if necessary
        if (x + 2 * shape.getRadius() > window.getSize().x || x < 0)
            dx = -dx;
        if (y + 2 * shape.getRadius() > window.getSize().y || y < 0)
            dy = -0.7*dy;

        // Draw circle and display window
        window.clear();
        shape.setPosition(x, y);
        window.draw(shape);
        window.display();

        // Wait for 1/60th of a second (60 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
