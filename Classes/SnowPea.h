#include "FiringPlant.h"
#include "FrozenPea.h"
#ifndef Snowpea_H
#define Snowpea_H

class SnowPea : public FiringPlant {
public:
	SnowPea(double x, double y);
	virtual bool actionTime(double time);
	virtual void fire();

};

#endif

