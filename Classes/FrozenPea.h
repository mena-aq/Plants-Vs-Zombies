#include "Projectile.h"
#include "Zombie.h"
#ifndef SnowPea_H
#define SnowPea_H

class FrozenPea : public Projectile {
public:
	FrozenPea();
	FrozenPea(double x, double y);
	virtual void attack();
};


#endif
