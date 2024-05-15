#include "ZombieFactory.h"
#include "PlantFactory.h"
#include "Defenders.h"
#include "Sidebar.h"
#include "Board.h"
#include "Timer.h"
#include "Pause.h"
#include <sstream>
using namespace std;

#ifndef Level_H
#define Level_H
class Level {
protected:
	int levelNum;
	const int totalZombies;
	int zombiesGenerated;
	int livesLeft;
	int money;
	Text sunCount;
	int playerResult; //1 is win,2 is lose, 3 is quit
	int levelScore;
	Text score;
	Sidebar sidebar;
	Board board;
	ZombieFactory* zombieFactory;
	PlantFactory* plantFactory;
	SunlightFactory* sunlightFactory;
	Defenders* defenders;
	Timer levelClock;
	double time;
	Font font;

public:
	Level(int levelNum, int totalZombies);
	virtual void handleInput(RenderWindow& window, bool& gameOn) = 0;
	int getLevelScore();
	int playLevel(RenderWindow& window);
	void initialiseFactories();
	void checkCollisions();
	void updateState();
	bool placePlant(int lane, int cell, double time);
	bool collectSun(int pixelX, int pixelY);
	void refreshLawn();
	bool checkProgress();
	void exitLevel();
	bool winLevel();
	bool loseLevel();
	void displayMoney(RenderWindow& window);
	void displayScore(RenderWindow& window);
	void createBack(RenderWindow& window);
	void drawLevel(RenderWindow& window);
	int cellCalculation(double x);
	int laneCalculation(double y);
};


#endif
