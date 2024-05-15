#include "AttackerZombie.h"
#include "Plant.h"

AttackerZombie::AttackerZombie() : Attacker(1), victim(nullptr), latestBiteTime(0) {

}
AttackerZombie::AttackerZombie(double x, double y, double w, double h, int health, double speed,int score) : Zombie(x, y, w, h, health, speed,score), Attacker(1), victim(nullptr), latestBiteTime(0) {

}
Plant* AttackerZombie::getVictim() {
	return victim;
}
bool AttackerZombie::isVictimAttached() {
	if (victim == nullptr)
		return false;
	return true;
}
bool AttackerZombie::actionTime(double time) {
	if (time - latestBiteTime >= 2) {
		latestBiteTime = time;
		return true;
	}
	return false;
}
void AttackerZombie::action(double time) {
	if (actionTime(time))
		this->attack();
}
void AttackerZombie::attachVictim(Plant* victim) {
	this->victim = victim;
	this->speed = 0;
	cout << "attached victim for zomboe";
}
void AttackerZombie::detachVictim() {
	cout << "detach zombie victim";
	if (this->victim != nullptr) {
		this->victim = nullptr;
	}
}
void AttackerZombie::attack() {
	if (this->victim != nullptr) {
		this->victim->updateHealth(this->damage);
		if (!this->victim->getIsAlive()) {
			detachVictim();
			restoreSpeed();
		}
	}
}
void AttackerZombie::checkCollision(Plant* object) {
	if (this->collider == object->collider && !this->isVictimAttached() && object->isEdible())
		this->attachVictim(object);

}