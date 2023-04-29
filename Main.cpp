#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>

#include "Ball.cpp"

// Allan is a legendary programmer

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Gravity Ballz ++");
    sf::CircleShape shape(100.f);
    sf::RectangleShape square(sf::Vector2f(300, 100));
    square.setPosition(400, 1400);
    square.setFillColor(sf::Color::Black);

    std::vector<Ball> balls; // Vector to hold the balls
    sf::Color color(rand() % 256, rand() % 256, rand() % 256);
    Ball ball(400, 400, ball.getX(), ball.getY(), 20, color);
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
        if (false){//rand() % 10 == 0) {
            sf::Color color(rand() % 256, rand() % 256, rand() % 256); // Generate a random color
            Ball ball(rand() % 1200, 0, 0, rand() % 10 + 5, rand() % 20 + 10, color); // Generate a random ball
            balls.push_back(ball); // Add the ball to the vector
        }
        //########TEST BED STARTS##########

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ball.moveLeft(); //ball.draw(window);
        }       
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            ball.moveRight(); 
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            ball.moveUp(); //ball.draw(window);
        }       
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            ball.moveDown(); 
        }

        ball.draw(window);
        //########TEST BED ENDS############

        // Move and draw all the balls
        //for (auto& ball : balls) {
        //    ball.move();
        //    ball.draw(window);
        //}

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
