#include "SimpleZombie.h"

SimpleZombie::SimpleZombie(double x, double y) : AttackerZombie(x, y, 2, 5, 60, 0.08, 10) { //3 hits
	this->texture.loadFromFile("../Images/simplezombie.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 67, 110));
}
void SimpleZombie::restoreSpeed() {
	this->speed = 0.08;
}