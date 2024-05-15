#pragma once
#include "Level.h"
#include "Pause.h"

#ifndef LevelOne_H
#define LevelOne_H

class LevelOne : public Level {
public:
	LevelOne();
	virtual void handleInput(RenderWindow& window, bool& gameOn);
};

#endif
