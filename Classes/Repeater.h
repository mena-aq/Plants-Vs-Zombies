#include "FiringPlant.h"
#ifndef Repeater_H
#define Repeater_H

class Repeater : public FiringPlant {
private:
	bool toggleShootState;
public:

	Repeater(double x, double y);
	virtual bool actionTime(double time);
	virtual void fire();
};

#endif
