
#include "Plant.h"
#include "SunlightFactory.h"
#ifndef Sunflower_H
#define Sunflower_H

class Sunflower : public Plant {
private:
	SunlightFactory* sunlightFactory;
	double latestSpawnTime;
public:
	Sunflower(double time, SunlightFactory* sunlightFactory);
	Sunflower(double x, double y, double time, SunlightFactory* sunlightFactory);
	void setTexture();
	virtual bool actionTime(double time);
	void action(double time);
	virtual void drawItems(RenderWindow& window);
	virtual void checkCollision(Zombie* zombie);
};

#endif