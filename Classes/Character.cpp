#include "Character.h"

Character::Character() : health(100), isAlive(true) {}
Character::Character(int health) : health(100), isAlive(true) {}
Character::Character(double x, double y, double w, double h, int health) :GameObject(x, y, w, h), health(health), isAlive(true) {}
bool Character::getIsAlive() {
	return isAlive;
}
int Character::getHealth() {
	return health;
}
void Character::updateHealth(int damage) {
	health -= damage;
	cout << health << endl;
	if (health <= 0)
		isAlive = false;
}
int Character::cellCalculation() {
	int cellX = 0;
	if (position.x >= 20 && position.x <= 59.5)
		cellX = (position.x - 20) / 4.5;
	return cellX;
}
int Character::laneCalculation() {
	int cellY = 0;
	if (position.y >= 5 && position.y <= 32)
		cellY = (position.y - 5) / 5.5;
	return cellY;
}