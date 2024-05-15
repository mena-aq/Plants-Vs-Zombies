#include "GameObject.h"

#ifndef Character_H
#define Character_H

class Character : public  GameObject {
protected:
	int health;
	bool isAlive;
public:
	Character();
	Character(int health);
	Character(double x, double y, double w, double h, int health = 100);
	bool getIsAlive();
	int getHealth();
	void updateHealth(int damage);
	int cellCalculation();
	int laneCalculation();
};


#endif
