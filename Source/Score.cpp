#include <SFML/Graphics.hpp>
#include <iostream>

class Score {
private:
    int x;
    int y;
    int score; // The current score
    sf::Font font; // The font used to display the score
    sf::Text text; // The text object used to display the score

public:
    // Constructor
    Score(int x, int y, int score, sf::Font font){
        this->x = x;
        this->y = y;
        this->score = score;
        this->font = font;
    }
    // Destructor
    ~Score() {
    }

    // Increment the score by 1
    void increment(int amount) {
        score+=amount;
    }

    // Increment the score by 1
    void decrement(int amount) {
        score-=amount;
    }

    void setScore(int add) {
        score += add;
    }

    // Get the current score
    int getScore() const {
        return score;
    }

    // Draw the score text to a given window
    void draw(sf::RenderWindow& window) {
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(score));
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        text.setPosition(x, y);
        window.draw(text);
    }
};
