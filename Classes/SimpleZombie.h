#include "AttackerZombie.h"

#ifndef SimpleZombie_H
#define SimpleZombie_H

class SimpleZombie : public AttackerZombie {
public:
	SimpleZombie(double x, double y);
	virtual void restoreSpeed();
};

#endif
