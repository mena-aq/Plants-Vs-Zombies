#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef Game_H
#define Game_H

class Game {
private:
	Player player;
public:
	Game();
	void playGame(RenderWindow& window);
};


#endif