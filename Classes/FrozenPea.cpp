#include "FrozenPea.h"

FrozenPea::FrozenPea() :Projectile(position, 0.5, 2, 1, 0) {
	this->texture.loadFromFile("../Images/frozenpea.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 30, 30));
}
FrozenPea::FrozenPea(double x, double y) :Projectile(x, y, 0.5, 2, 1, 0) {
	this->texture.loadFromFile("../Images/frozenpea.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 30, 30));
}
void FrozenPea::attack() {
	if (this->victim != nullptr && !((this->victim)->isFrozen())) {
		this->victim->updateSpeed(0.5);
		this->victim->freeze();
		detachVictim();
	}
	else
		detachVictim();
}