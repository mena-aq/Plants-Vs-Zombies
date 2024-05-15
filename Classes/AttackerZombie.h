#include "Zombie.h"
#include "Attacker.h"

#ifndef AttackerZombie_H
#define AttackerZombie_H

class AttackerZombie : public Zombie, public Attacker {
protected:
	Plant* victim;
	double latestBiteTime;

public:
	AttackerZombie();
	AttackerZombie(double x, double y, double w, double h, int health, double speed,int score);
	Plant* getVictim();
	bool isVictimAttached();
	virtual bool actionTime(double time);
	virtual void action(double time);
	void attachVictim(Plant* victim);
	void detachVictim();
	virtual void attack();
	virtual void checkCollision(Plant* object);
};

#endif
