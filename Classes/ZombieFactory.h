#pragma once
#include "SimpleZombie.h"
#include "FlyingZombie.h"
#include "FootballZombie.h"
#include "DancingZombie.h"

class DancingZombie;

#ifndef ZombieFactory_H
#define ZombieFactory_H

class ZombieFactory {
private:
	//static ZombieFactory* factory;
	Zombie** zombies;
	int numZombies;
	//string listOfZombies[2] = { "simple","flying" };
	double spawnInterval;
	double latestSpawnTime;
	//ZombieFactory(double time);
public:
	ZombieFactory(double time);
	//static ZombieFactory* getFactory(double time);
	int getNumZombies();
	void setSpawnInterval(double interval);
	Zombie** getZombies();
	bool spawnZombie(double time);
	void createZombie(int level, double time);
	void addZombie(Zombie* newZombie);
	void removeZombie(int i);
	void removeDeadZombies(int& levelScore);
	void move(double time);
	void action(double time);
	void draw(RenderWindow& window);

	Zombie* operator[](int index);
	~ZombieFactory();
};


#endif
