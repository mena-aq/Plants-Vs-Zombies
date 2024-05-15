#include "MovingObject.h"
#include "Attacker.h"
#include "Zombie.h"
#include "Animation.h"
#ifndef Projectile_H
#define Projectile_H

class Projectile : public GameObject, public MovingObject, public Attacker {
protected:
	Zombie* victim;
	Animation animation;
	bool expired;
public:
	Projectile();
	Projectile(Position position, double w, double h, double speed, int damage);
	Projectile(double x, double y, double w, double h, double speed, int damage);
	bool getExpired();
	virtual void move(double time);
	Zombie* getVictim();
	bool isVictimAttached();
	void attachVictim(Zombie* victim);
	virtual void attack();
	void detachVictim();
	virtual void draw(RenderWindow& window);
	virtual void checkCollision(GameObject* object);
};

#endif

