#ifndef DSDER_H_
#define DSDER_H_

#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class HighScoreScreen {
    int selected;
public:
    Sprite ins;
    Font font;
    Texture tex;
    int size = 12;
    Text* txt = new Text[size];
    bool music_flag;
    bool Exit = false;
    float timer;
    Clock clock;

    HighScoreScreen();
    void display_menu(RenderWindow& window);
};

#endif 
