#include "Peashooter.h"

//default
Peashooter::Peashooter(double x, double y) : FiringPlant(x, y, 2, 1, 100) {
	this->texture.loadFromFile("../Images/peashooter.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 71, 72));
}
bool Peashooter::actionTime(double time) {
	if (time - latestShootTime >= 2) {
		cout << "time to shoot";
		latestShootTime = time;
		return true;
	}
	return false;
}

void Peashooter::fire() {
	cout << "fire";
	Projectile** tmp = new Projectile * [numProjectiles + 1];
	for (int i = 0; i < numProjectiles; i++)
		tmp[i] = projectiles[i];
	tmp[numProjectiles] = new Pea(this->position.x + 2, this->position.y);
	delete[] projectiles;
	projectiles = tmp;
	numProjectiles++;
}