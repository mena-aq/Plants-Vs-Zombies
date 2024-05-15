#pragma once
#include "Character.h"
#include "MovingObject.h"

class Plant;

#ifndef Zombie_H
#define Zombie_H

class Zombie : public Character, public MovingObject{
protected:
	int score;
	bool frozen;
public:
	Zombie();
	Zombie(double x, double y, double w, double h, int health, double speed,int score);
	int getScore();
	bool isFrozen();
	void freeze();
	virtual void move(double time);
	virtual void action(double time) = 0;
	virtual void checkCollision(Plant* object) = 0;
	virtual void restoreSpeed() = 0;
};

#endif
