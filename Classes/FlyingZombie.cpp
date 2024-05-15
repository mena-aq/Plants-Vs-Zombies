#include "FlyingZombie.h"

FlyingZombie::FlyingZombie(double x, double y) : Zombie(x, y, 2, 6, 60, 0.1, 15) { //3 hits
	this->texture.loadFromFile("../Images/flyingzombie.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 69, 120));
}
void FlyingZombie::action(double time) {
	// no action
}
void FlyingZombie::checkCollision(Plant* object) {
	// no action on collision
}
void FlyingZombie::restoreSpeed() {
	this->speed = 0.1;
}
void FlyingZombie::move(double time) {
	position.x -= speed;
	collider.x -= speed;
}