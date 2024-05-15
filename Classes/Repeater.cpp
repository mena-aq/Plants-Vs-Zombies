#include "Repeater.h"
#include "Pea.h"

Repeater::Repeater(double x, double y) : FiringPlant(x, y, 3, 2, 200), toggleShootState(1) {
	this->texture.loadFromFile("../Images/repeater.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 69, 71));
}
bool Repeater::actionTime(double time) {
	if (time - latestShootTime >= 2 && toggleShootState) {
		latestShootTime = time;
		toggleShootState = 0;
		return true;
	}
	if (time >= latestShootTime + 0.25 && !toggleShootState) {
		toggleShootState = 1;
		return true;
	}
	return false;
}
void Repeater::fire() {
	Projectile** tmp = new Projectile * [numProjectiles + 1];
	for (int i = 0; i < numProjectiles; i++)
		tmp[i] = projectiles[i];
	tmp[numProjectiles] = new Pea(this->position.x + 2, this->position.y);
	delete[] projectiles;
	projectiles = tmp;
	numProjectiles++;
}