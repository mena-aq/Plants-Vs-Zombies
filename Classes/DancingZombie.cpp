#include "DancingZombie.h"
#include "ZombieFactory.h"

DancingZombie::DancingZombie(double x, double y, bool spawner, double time, ZombieFactory* factory) : AttackerZombie(x, y, 2, 5, 60, 0.25,25), spawnTime(time), spawner(spawner), spawnedZombies(false), targetCell(-1),targetLane(-1),zombieFactory(factory) {
	this->texture.loadFromFile("../Images/dancingzombie.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 64, 110));
}
bool DancingZombie::timeToSpawn(double time) {
	if (!spawnedZombies && time - spawnTime >= 7)
		return true;
	return false;
}
void DancingZombie::action(double time) {
	if (actionTime(time))
		this->attack();
	if (spawner && !spawnedZombies && timeToSpawn(time)) {
		summonZombie(time);
		this->spawner = false;
	}
	if (targetCell<0 && targetLane<0)
		diagonal();
}
void DancingZombie::diagonal() {
	if ((position.x >= 39.5 && position.x <= 41.5) || (position.x >= 44 && position.x <= 45) || (position.x >= 48.5 && position.x <= 49.5) || (position.x >= 53 && position.x <= 54) || (position.x >= 57.5 && position.x <= 58.5)) {
		int choice = rand() % 6; //0 diagonal move(rarer chance)
		//int choice = 1;
		if (choice==0) {
			int lane = laneCalculation();
			int cell = cellCalculation();
			if (lane <= 1) {
				cout << "down";
				targetLane = lane + 2;
			}
			if (lane >= 2) {
				cout << "up";
				targetLane = lane - 2;
			}
			targetCell = cell - 2;
			cout << "target lane: " << targetLane << " target cell: " << targetCell;
		}
	}
}
void DancingZombie::move(double time) {
	if (this->isVictimAttached() && (targetCell >= 0 || targetLane >= 0)) {
		targetCell = -1;
		targetLane = -1;
	}
	if (targetCell < 0 || targetLane < 0) {
		position.x -= speed;
		collider.x -= speed;
	}
	else {
		if (position.y < 5 + (targetLane * 5.5) && position.x > 20 + (targetCell * 4.5)) {
			position.y += speed;
			collider.y += speed;
			position.x -= speed;
			collider.x -= speed;
		}
		else if (position.y > 5 + (targetLane * 5.5) && position.x > 20 + (targetCell * 4.5)) {
			position.y -= speed;
			collider.y -= speed;
			position.x -= speed;
			collider.x -= speed;
		}
		else {
			targetCell = -1;
			targetLane = -1;
		}
	}
}
void DancingZombie::summonZombie(double time) {
	DancingZombie* zombie1 = new DancingZombie(this->position.x + 5, this->position.y, false,time,nullptr);
	DancingZombie* zombie2 = new DancingZombie(this->position.x - 5, this->position.y, false, time,nullptr);
	DancingZombie* zombie3 = new DancingZombie(this->position.x, this->position.y + 5.5, false, time,nullptr);
	DancingZombie* zombie4 = new DancingZombie(this->position.x, this->position.y - 5.5, false, time,nullptr);
	zombieFactory->addZombie(zombie1);
	zombieFactory->addZombie(zombie2);
	zombieFactory->addZombie(zombie3);
	zombieFactory->addZombie(zombie4);
}
void DancingZombie::restoreSpeed() {
	this->speed = 0.25;
}
