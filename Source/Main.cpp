// Gravity Ballz ++ 

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "Ball.cpp"
#include "Player.cpp"
#include "Score.cpp"
#include "../Headers/Themes.hpp"
#include "../Headers/Globals.hpp"
#include "State.cpp"

int randomNum(int min, int max) {
    int shift = min;
    int range = max-min+1;
    int rum = rand() % range + shift;
    return rum;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Gravity Ballz ++");

    std::vector<Ball> balls; // Vector to hold the balls

    sf::Texture eyeTex;
    if (!eyeTex.loadFromFile("Media/Images/eye.png")){
    }
    sf::Texture coinTex;
    if (!coinTex.loadFromFile("Media/Images/coin.png")){
    }
    sf::Texture playerTex;
    if (!playerTex.loadFromFile("Media/Images/player.png")){
    }

    // Font
    sf::Font font;
    if (!font.loadFromFile("Media/Fonts/caviar/Caviar_Dreams_Bold.ttf")) {
        // error handling
    }

    // Music
    sf::Music music;
    if (!music.openFromFile("Media/Sounds/Music/skellige.wav")) {
        // error loading file
        return -1;
    }

    // Pause menu
    sf::Text pauseMessage("Game Paused. Press ESC to resume.", font, 32);
    pauseMessage.setPosition(window.getSize().x / 2 - pauseMessage.getLocalBounds().width / 2,
        window.getSize().y / 2 - pauseMessage.getLocalBounds().height / 2);

    // Score object
    Score score(
        SCREEN_WIDTH - 100, // X position
        50, // Y position
        0, // Starting score
        font // Font
    );

    // Player object
    Player player(
        150, // Width
        50, // Height
        SCREEN_WIDTH / 3, // X position
        SCREEN_HEIGHT - SCREEN_HEIGHT * 0.1, // Y position
        12, // X velocity
        0, // Y velocity
        playerTex // Texture
    );

    // State machine
    State state;

    music.setVolume(10);
    music.play();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Checks if user pauses game (Presses ESC key)
            state.checkForPause();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && state.isPaused()) {
                music.pause();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !state.isPaused()) {
                music.play();
            }
        }
        if (!state.isPaused()) {
            // Check if it's time to create a new ball
            if (rand() % 80 == 0) {
                //sf::Color color(rand() % 256, rand() % 256, rand() % 256); // Generate a random color
                Ball enemy(
                    randomNum(30, SCREEN_WIDTH - 30), // X Coordinate
                    -50,                  // Y Coordinate
                    0,                  // X Velocity
                    rand() % 10 + 5,    // Y Velocity
                    rand() % 20 + 10,   // Radius
                    eyeTex,               // Texture
                    true
                );
                balls.push_back(enemy);
                Ball coin(
                    randomNum(30, SCREEN_WIDTH - 30), // X Coordinate
                    -50,                // Y Coordinate
                    0,                  // X Velocity
                    rand() % 10 + 5,    // Y Velocity
                    20,   // Radius
                    coinTex,               // Texture
                    false
                );
                balls.push_back(coin); // Add the ball to the vector
            }

            // Move and draw all the balls
            for (auto ball = balls.begin(); ball != balls.end(); ++ball) {
                ball->gravity();
                ball->draw(window);
                if (player.hitbox(window).intersects(ball->hitbox(window))) {
                    if (ball->enemy()) {
                        // handle collision with enemy ball
                        // for example, remove the ball from the vector and decrement the score
                        ball = balls.erase(ball);
                        score.decrement(2);
                        // since we have erased an element from the vector, we need to decrement the iterator
                        --ball;
                    } else if (!ball->enemy()) {
                        // handle collision with coin
                        // for example, remove the ball from the vector and increment the score
                        ball = balls.erase(ball);
                        score.increment(1);
                        // since we have erased an element from the vector, we need to decrement the iterator
                        --ball;
                    }
                }
            }

            score.draw(window);
            player.draw(window);
            player.keyboard();

        } else if (state.isPaused()) {
            // Draw the pause message if the game is paused
            window.draw(pauseMessage);
        }
        // Display the window
        window.display();
        // Set background colour
        window.clear(sf::Color(230, 196, 147));
        // Wait for 1/60th of a second (60 FPS)
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
