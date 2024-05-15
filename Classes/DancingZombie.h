#pragma once
#include "AttackerZombie.h"
//#include "ZombieFactory.h"

class ZombieFactory;

#include "AttackerZombie.h"
#ifndef DancingZombie_H
#define DancingZombie_H

class ZombieFactory;

class DancingZombie : public AttackerZombie {
private:
	double spawnTime;
	bool spawnedZombies; //only allowed once
	bool spawner;
	int targetCell;
	int targetLane;
	ZombieFactory* zombieFactory;
public:
	DancingZombie(double x, double y, bool spawner, double time, ZombieFactory* factory);
	bool timeToSpawn(double time);
	virtual void action(double time);
	void diagonal();
	virtual void move(double time);
	void summonZombie(double time);
	virtual void restoreSpeed();
};

#endif
