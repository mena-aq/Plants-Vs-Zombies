#pragma once

#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class Instructions
{
int selected;
public:
    Sprite ins;
    Font font;
    Texture tex;
    int size = 1;
    Text* Ins = new Text[size];
    bool music_flag;

    //SoundBuffer hoverbuffer;
    //SoundBuffer selectbuffer;
    //Sound hoversound;
    //Sound selectsound;

    Instructions();

    void display_menu(RenderWindow& window);

    void moveup();

    void movedown();

    int getSelected();
};