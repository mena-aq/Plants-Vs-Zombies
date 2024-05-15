#include "LaneDefender.h"

LaneDefender::LaneDefender(double x, double y) :GameObject(x, y, 2.5, 4), MovingObject(0) {
	this->setTexture();
}
void LaneDefender::attachVictim(Zombie* victim) {
	this->victim = victim;
}
Zombie* LaneDefender::getVictim() {
	return victim;
}
void LaneDefender::attack() {
	victim->updateHealth(victim->getHealth());
	victim = nullptr;
}
void LaneDefender::setTexture() {
	this->texture.loadFromFile("../Images/lawnmower.png"); 
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 75, 64));
}
void LaneDefender::checkCollision(Zombie* object) {
	if (this->collider == object->collider) {
		if (this->speed == 0)
			this->speed = 2;
		attachVictim(object);
	}
}
void LaneDefender::move(double time) {
	position.x += speed;
	collider.x += speed;
}