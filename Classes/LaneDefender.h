#include "GameObject.h"
#include "Attacker.h"
#include "MovingObject.h"
#include "Zombie.h"

#ifndef LaneDefender_H
#define LaneDefender_H

class LaneDefender : public GameObject,public Attacker,public MovingObject {
private:
	Zombie* victim;
public:
	LaneDefender(double x, double y);
	void attachVictim(Zombie* victim);
	Zombie* getVictim();
	virtual void attack();
	void setTexture();
	virtual void checkCollision(Zombie* object);
	virtual void move(double time);
};

#endif