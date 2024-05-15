#include "FiringPlant.h"

FiringPlant::FiringPlant() :Plant(0), projectiles(nullptr), numProjectiles(0), latestShootTime(0) {}
FiringPlant::FiringPlant(int price) :Plant(price), projectiles(nullptr), numProjectiles(0), latestShootTime(0) {}
FiringPlant::FiringPlant(double x, double y, double w, double h, int price) : Plant(x, y, w, h, price), projectiles(nullptr), numProjectiles(0), latestShootTime(0) {}
void FiringPlant::action(double time) {
	if (actionTime(time))
		this->fire();
	for (int i = 0; i < numProjectiles; i++)
		projectiles[i]->move(time);
	removeUsedProjectiles();
}
void FiringPlant::checkCollision(Zombie* zombie) {	
	for (int i = 0; i < numProjectiles; i++) {
		if (projectiles[i]->collider == zombie->collider && !(projectiles[i]->getExpired())) {
			projectiles[i]->attachVictim(zombie);
			projectiles[i]->attack();
		}
	}
}
void FiringPlant::removeProjectile(int i) {
	projectiles[i]->detachVictim();
	delete projectiles[i];
	projectiles[i] = nullptr;
	Projectile** tmp = new Projectile * [numProjectiles - 1];
	int j = 0;
	for (int i = 0; i < numProjectiles; i++) {
		if (projectiles[i] != nullptr) {
			tmp[j++] = projectiles[i];
		}
	}
	delete[] projectiles;
	projectiles = tmp;
	numProjectiles--;
}
void FiringPlant::removeUsedProjectiles() {
	for (int i = 0; i < numProjectiles; i++) {
		if (!(projectiles[i]->getExists()))
			removeProjectile(i);
	}
}
void FiringPlant::drawItems(RenderWindow& window) {
	drawProjectiles(window);
}
void FiringPlant::drawProjectiles(RenderWindow& window) {
	for (int i = 0; i < numProjectiles; i++)
		projectiles[i]->draw(window);
}
void FiringPlant::draw(RenderWindow& window) {
	sprite.setPosition(position.x * box, position.y * box);
	window.draw(sprite);
}
FiringPlant::~FiringPlant() {
	for (int i = 0; i < numProjectiles; i++)
		delete projectiles[i];
	delete[] projectiles;
}