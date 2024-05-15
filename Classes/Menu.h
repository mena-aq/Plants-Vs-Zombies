#include <SFML/Audio.hpp>
#include "InputName.h"
#include "Options.h"
#include "Instructions.h"
#include "HighScores.h"
#include "LevelScreen.h"
//#include"grid.h"
//#include"level.h"
#include <iostream>
using namespace std;
using namespace sf;

#ifndef Menu_H
#define Menu_H

class Menu {
private:
    int selected;
public:
    InputName N;
    Options optionMenu;
    Instructions InstructionsMenu;
    HighScoreScreen HS;
    LevelScreen levels;
    Sprite menu;
    Texture menu_tx;
    Music music;
    Font font;
    Text* main_menu = new Text[5];
    Text score;
    Player* player;
    bool music_pause;
    SoundBuffer hoverbuffer;
    SoundBuffer selectbuffer;
    Sound hoversound;
    Sound selectsound;

    bool musicIS;


    Menu(Player* player);
    void display_menu(RenderWindow& window);
    void executeAction(int index, RenderWindow& window,bool& onWindow);
    void moveup();
    void movedown();
    int getSelected();
};

#endif
//
//
//
//
