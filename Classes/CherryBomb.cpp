#include "CherryBomb.h"

CherryBomb::CherryBomb(double x, double y, double time) :Plant(x, y, 3, 4, 150, 1000), victims(nullptr), numVictims(0), explodeTime(time), activated(false) { 
	this->edible = false;
	this->collider.radius = 6;
	this->texture.loadFromFile("../Images/cherrybomb.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 71, 63));
}
bool CherryBomb::actionTime(double time) {
	if (time - explodeTime >= 3) //3s delay before exploding
		return true;
	return false;
}
void CherryBomb::action(double time) {
	if (actionTime(time) && !activated)
		activated = true;
	else if (activated)
		this->explode();
}
void CherryBomb::explode() {
	for (int i = 0; i < numVictims; i++)
		victims[i]->updateHealth(victims[i]->getHealth());
	//detach victim
	this->isAlive = false;
}
void CherryBomb::addVictim(Zombie* victim) {
	Zombie** tmp = new Zombie * [numVictims + 1];
	for (int i = 0; i < numVictims; i++)
		tmp[i] = victims[i];
	tmp[numVictims] = victim;
	delete[] victims;
	victims = tmp;
	numVictims++;
	cout << "num victim: " << numVictims << endl;

}
void CherryBomb::checkCollision(Zombie* zombie) {
	if (activated) {
		if (this->collider == zombie->collider) {
			cout << "cherry bomb collision";
			addVictim(zombie);
		}
	}
}
void CherryBomb::drawItems(RenderWindow& window) {

}