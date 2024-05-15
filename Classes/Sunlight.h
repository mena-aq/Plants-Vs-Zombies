#include "MovingObject.h"

#ifndef Sunlight_H
#define Sunlight_H

class Sunlight : public GameObject, public MovingObject {
private:
	double spawnTime;
public:
	Sunlight();
	Sunlight(double x, double y, double spawnTime, double speed);
	void setTexture();
	void checkExpire(double moneyTime);
	virtual void move(double time);
	virtual void checkCollision(GameObject* object);
};

#endif
