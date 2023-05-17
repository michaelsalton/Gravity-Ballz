#include <SFML/Graphics.hpp>

class State {
private:
    bool startMenu = true;
    bool paused = false;
    bool musicIsOn = false;

public:
    //Constructot
    State() {
    }

    void pause() {
        paused = !paused;
        musicIsOn = !musicIsOn;
    }

    bool isPaused(){
        return paused;
    }
 
    bool musicIsPlaying(){
        return musicIsOn;
    }

    void checkForPause(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            pause();
        }
    } 
};
