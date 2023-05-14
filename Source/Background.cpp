#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Headers/Globals.hpp"


class Background {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Background(std::string texturePath) {
        if (!texture.loadFromFile(texturePath)){
            std::cerr << "Error loading texture\n";
        }
        sprite.setScale(1, 1);
        sprite.setTexture(texture);
        texture.setRepeated(true);
        sprite.setTextureRect(sf::IntRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));
    }

    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }
};