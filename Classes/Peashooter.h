#include "FiringPlant.h"
#include "Pea.h"
#ifndef Peashooter_H
#define Peashooter_H

class Peashooter : public FiringPlant {
public:
	//default
	Peashooter(double x, double y);
	virtual bool actionTime(double time);
	virtual void fire();
};

#endif
