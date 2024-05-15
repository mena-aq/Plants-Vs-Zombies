#include "Sunlight.h"

Sunlight::Sunlight() {
	this->setTexture();
}
Sunlight::Sunlight(double x, double y, double spawnTime, double speed) : GameObject(x, y, 2.5, 2.5), MovingObject(speed), spawnTime(spawnTime) {
	this->setTexture();
}
void Sunlight::setTexture() {
	this->texture.loadFromFile("../Images/sunlight.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 60, 60));
}
void Sunlight::checkExpire(double moneyTime) {
	if (moneyTime - spawnTime >= 5 && speed <= 0) {
		this->exists = false;

	}
}
void Sunlight::move(double time) {
	position.y += speed;
}
void Sunlight::checkCollision(GameObject* object) {

}