#include "Level.h"
#include "Pause.h"
#include "Fog.h"

#ifndef LevelFour_H
#define LevelFour_H

class LevelFour : public Level {
private:
	Fog fog[5];
public:
	LevelFour();
	virtual void handleInput(RenderWindow& window, bool& gameOn);
	virtual void drawLevel(RenderWindow& window);
};

#endif
