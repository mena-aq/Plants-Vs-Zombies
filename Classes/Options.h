#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
//#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;


#ifndef Options_H
#define Options_H

class Options {
    int selected;
public:
    Sprite menu;
    Texture menu_tx;
    Font font;
    int size = 2;
    Text* options_menu = new Text[size];
    bool musicFlag;

    //SoundBuffer hoverbuffer;
    //SoundBuffer selectbuffer;
    //Sound hoversound;
    //Sound selectsound;

    // Constructor
    Options();
    void display_menu(RenderWindow& window);
    void executeOption(int index, RenderWindow& window, bool& onWindow);
};

#endif 
