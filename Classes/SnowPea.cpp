#include "SnowPea.h"

SnowPea::SnowPea(double x, double y) :FiringPlant(x, y, 3, 2, 175) {
	this->texture.loadFromFile("../Images/snowpea.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 85, 68));
}
bool SnowPea::actionTime(double time) {
	if (time - latestShootTime >= 2) {
		latestShootTime = time;
		return true;
	}
	return false;
}
void SnowPea::fire() {
	Projectile** tmp = new Projectile * [numProjectiles + 1];
	for (int i = 0; i < numProjectiles; i++)
		tmp[i] = projectiles[i];
	tmp[numProjectiles] = new FrozenPea(this->position.x + 2, this->position.y);
	delete[] projectiles;
	projectiles = tmp;
	numProjectiles++;
}