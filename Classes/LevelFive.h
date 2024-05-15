#include "Level.h"
#include "Pause.h"

#ifndef LevelFive_H
#define LevelFive_H

class LevelFive : public Level {
public:
	LevelFive();
	virtual void handleInput(RenderWindow& window, bool& gameOn);
};

#endif
