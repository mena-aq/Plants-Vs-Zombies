#pragma once

#include "Options.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Pause {
private:
    Sprite background;
    Texture backgroundTexture;
    Font font;
    Text pause_menu[3];
    int selected;
    bool musicFlag;
    bool exit;
    Options o;
    //SoundBuffer hoverbuffer;
    //SoundBuffer selectbuffer;
    //Sound hoversound;
    //Sound selectsound;
    //Music music;

public:
    Pause();

    void display_menu(RenderWindow& window, bool& gameOn);
    void executeAction(int index, RenderWindow& window, bool& onWindow, bool& gameOn);
};