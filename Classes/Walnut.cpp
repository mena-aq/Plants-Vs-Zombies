#include "Walnut.h"

Walnut::Walnut(double x, double y, double time) : Plant(x, y, 1.5, 2, 50, 72), MovingObject(1), creationTime(time), victim(nullptr) {
	this->texture.loadFromFile("../Images/walnut.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 65, 74));
}
bool Walnut::actionTime(double time) {
	return true;
}
void Walnut::action(double time) {
	move(time);
}
void Walnut::detachVictim() {
	this->victim = nullptr;
}
void Walnut::drawItems(RenderWindow& window) {
	//not yet
}
void Walnut::checkCollision(Zombie* zombie) {
	if (this->collider == zombie->collider && this->speed > 0) {
		this->speed = 0;
	}
}
void Walnut::move(double time) {
	position.x += speed;
	collider.x += speed;
}