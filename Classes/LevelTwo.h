#include "Level.h"

#ifndef LevelTwo_H
#define LevelTwo_H

class LevelTwo : public Level {
public:
	LevelTwo();
	virtual void handleInput(RenderWindow& window, bool& gameOn);
		
};

#endif
