#include "Plant.h"
#include "MovingObject.h"
#include "Zombie.h"
#ifndef Walnut_H
#define Walnut_H

class Walnut : public Plant, public MovingObject {
private:
	double creationTime;
	Zombie* victim;
public:
	Walnut(double x, double y, double time);
	virtual bool actionTime(double time);
	virtual void action(double time);
	void detachVictim();
	virtual void drawItems(RenderWindow& window);
	virtual void checkCollision(Zombie* zombie);
	virtual void move(double time);
};

#endif

