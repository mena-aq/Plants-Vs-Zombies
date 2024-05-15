#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef Timer_H
#define Timer_H

struct Timer {
    sf::Clock clock;
    float runTime;
    bool paused;

    Timer();
    void reset();
    void start();
    void pause();
    float getTime();
};

#endif