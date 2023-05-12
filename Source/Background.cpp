#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Headers/Globals.hpp"


class Background {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Background();
    Background(std::string texturePath) {
        if (!texture.loadFromFile(texturePath)){
            std::cerr << "Error loading texture\n";
        }
        sprite.setScale(0.5, 0.5);
        sprite.setTexture(texture);
        texture.setRepeated(true);
        sprite.setTextureRect(sf::IntRect(0,0,SCREEN_WIDTH*2,SCREEN_HEIGHT*2));
    }

    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }
};