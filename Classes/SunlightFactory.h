#include "Sunlight.h"

#ifndef SunlightFactory_H
#define SunlightFactory_H

class SunlightFactory {
private:
	Sunlight** sunlight;
	int numSuns;
	double latestSpawnTime;
	double spawnInterval;
public:
	SunlightFactory(double time);
	bool actionTime(double time);
	int getNumSuns();
	double getLatestSpawnTime();
	void setSpawnInterval(double interval);
	void action(double time);
	void spawnSun(double x, double y, double sunflowerLatestSpawnTime); //sunflower
	void spawnSun(double x, double y); //sky
	void removeSun(int i);
	void removeExpiredSuns(double moneyTime);
	void fall(double time);
	Sunlight* operator[](int index);
	void draw(RenderWindow& window);
	~SunlightFactory();
};

#endif
