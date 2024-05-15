#pragma once
#include <SFML/Graphics.hpp>
#include "LevelButton.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"
#include "LevelFour.h"
#include "LevelFive.h"
#include "GameOverMenu.h"
#include "Player.h"
#include <iostream>

using namespace sf;
using namespace std;

class LevelScreen {
private:
    Sprite background;
    Texture backgroundTexture;
    Font font;
    Text backButton;
    Text score;
    LevelButton buttons[6];
    Texture textures[6];
    Texture lockedTextures[6];
    //Music music;
    Color normalColor = Color::White;  // Color when not hovering
    Color hoverColor = Color::Red;    // Color when hovering
    Player* player;
public:
    LevelScreen(Player* player);
    void display_menu(RenderWindow& window);
    void initialiseTextures();
    void initialiseButtons();
    void checkButtonClick(Vector2f mousePosition, RenderWindow& window);
    void unlockLevels();
    void drawButtons(RenderWindow& window);
    void initializeText(Text& text, const string& str, float x, float y);
    void updateTextColor(Text& text, int mouseX, int mouseY);
    void checkTextClick(Text& text, int mouseX, int mouseY, int levels, RenderWindow& window, bool& onWindow);
};
