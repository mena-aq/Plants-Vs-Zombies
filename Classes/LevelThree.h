#include "Level.h"

#ifndef LevelThree_H
#define LevelThree_H

class LevelThree : public Level {
public:
	LevelThree();
	virtual void handleInput(RenderWindow& window, bool& gameOn);
};

#endif

