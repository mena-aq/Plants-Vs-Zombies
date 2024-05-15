#include "GameObject.h"
#ifndef MovingObject_H
#define MovingObject_H

class MovingObject {
protected:
	double speed;
public:
	MovingObject(double speed = 0);
	double getSpeed();
	void updateSpeed(double factor);
	virtual void move(double time) = 0;
};

#endif
