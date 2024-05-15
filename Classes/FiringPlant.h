#include "Plant.h"
#include "Projectile.h"
#ifndef FiringPlant_H
#define FiringPlant_H

class FiringPlant : public Plant {
protected:
	Projectile** projectiles;
	int numProjectiles;
	double latestShootTime;
public:
	FiringPlant();
	FiringPlant(int price);
	FiringPlant(double x, double y, double w, double h, int price = 0);
	virtual bool actionTime(double time) = 0;
	virtual void fire() = 0;
	virtual void action(double time);
	virtual void checkCollision(Zombie* zombie);
	void removeProjectile(int i);
	void removeUsedProjectiles();
	virtual void drawItems(RenderWindow& window);
	void drawProjectiles(RenderWindow& window);
	virtual void draw(RenderWindow& window);
	virtual ~FiringPlant();
};

#endif
