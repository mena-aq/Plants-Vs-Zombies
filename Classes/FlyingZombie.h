#include "Zombie.h"

#ifndef FlyingZombie_H
#define FlyingZombie_H

class FlyingZombie : public Zombie {
public:
	FlyingZombie(double x, double y);
	void action(double time);
	virtual void checkCollision(Plant* object);
	virtual void restoreSpeed();
	virtual void move(double time);
};

#endif
