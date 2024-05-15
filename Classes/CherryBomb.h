#include "Plant.h"
#include "Zombie.h"
#ifndef CherryBomb_H
#define CherryBomb_H

class CherryBomb : public Plant {
private:
	Zombie** victims;
	int numVictims;
	double explodeTime;
	bool activated;
public:
	CherryBomb(double x, double y, double time);
	virtual bool actionTime(double time);
	virtual void action(double time);
	void explode();
	void addVictim(Zombie* victim);
	virtual void checkCollision(Zombie* zombie);
	virtual void drawItems(RenderWindow& window);
};

#endif