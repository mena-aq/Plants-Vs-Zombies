#pragma once
#ifndef InputName_H
#define InputName_H

#include "Player.h"
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class InputName
{
    int selected;
public:
    Sprite ins;
    Font font;
    Texture tex;
    int size = 2;
    Text* txt = new Text[size];
    bool music_flag;
    bool Exit = false;
    float timer;
    Clock clock;

    //SoundBuffer hoverbuffer;
    //SoundBuffer selectbuffer;
    //Sound hoversound;
    //Sound selectsound;

    //SoundBuffer music;
    //Sound MUSICA;

    InputName();

    string display_menu(RenderWindow& window);

    void moveup();
    void movedown();

    int getSelected();
};
#endif