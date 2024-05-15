#include "Pea.h"

Pea::Pea() :Projectile(position, 0.5, 2, 1, 20) {
	this->texture.loadFromFile("../Images/pea.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 30, 30));
}
Pea::Pea(double x, double y) :Projectile(x, y, 0.5, 2, 1, 20) {
	this->texture.loadFromFile("../Images/pea.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 30, 30));
}