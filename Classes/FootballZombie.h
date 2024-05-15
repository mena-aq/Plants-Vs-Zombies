#include "AttackerZombie.h"

#ifndef FootballZombie_H
#define FootballZombie_H

class FootballZombie : public AttackerZombie {
private:
	float changeDirectionTime;
	int currentLane;
	int targetLane;
public:
	FootballZombie(double x, double y, double time);
	bool timeToSwitchLane(double time);
	void switchLane();
	virtual void move(double time);
	virtual void restoreSpeed();
};

#endif

