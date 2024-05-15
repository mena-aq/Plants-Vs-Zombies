#include "Zombie.h"
#include "Plant.h"

Zombie::Zombie() : score(0),frozen(false){}
Zombie::Zombie(double x, double y, double w, double h, int health, double speed,int score) : Character(x, y, w, h, health), MovingObject(speed), score(score), frozen(false){}

int Zombie::getScore() {
	return score;
}
bool Zombie::isFrozen() {
	return frozen;
}
void Zombie::freeze() {
	this->frozen = true;
}
void Zombie::move(double time) {
	position.x -= speed;
	collider.x -= speed;
}
