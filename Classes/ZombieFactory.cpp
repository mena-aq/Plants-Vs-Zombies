#include "ZombieFactory.h"
#include "DancingZombie.h"


ZombieFactory::ZombieFactory(double time) : zombies(nullptr), numZombies(0), spawnInterval(15), latestSpawnTime(time) {}

int ZombieFactory::getNumZombies() {
	return numZombies;
}

void ZombieFactory::setSpawnInterval(double interval) {
	spawnInterval = interval;
}

Zombie** ZombieFactory::getZombies() {
	return zombies;
}
bool ZombieFactory::spawnZombie(double time) { 
	if (time - latestSpawnTime >= spawnInterval) {
		latestSpawnTime = time;
		cout << "zombie spawned at " << latestSpawnTime;
		return true;
	}
	return false;
}
void ZombieFactory::createZombie(int level, double time) {
	Zombie* newZombie = nullptr;
	int lane = rand() % 5;
	if (level == 1)
		newZombie = new SimpleZombie(60, 5 + (lane * 5.5));
	else { 
		int type = rand() % 4;
		if (type == 0)
			newZombie = new SimpleZombie(60, 5 + (lane * 5.5));
		else if (type == 1)
			newZombie = new FlyingZombie(60, 5 + (lane * 5.5));
		else if (type == 2)
			newZombie = new FootballZombie(60, 5 + (lane * 5.5), time);
		else
			newZombie = new DancingZombie(59, 5 + (lane * 5.5), true, time, this);
	}
	Zombie** tmp = new Zombie * [numZombies + 1];
	for (int i = 0; i < numZombies; i++)
		tmp[i] = zombies[i];
	tmp[numZombies] = newZombie;
	delete[] zombies;
	zombies = tmp;
	numZombies++;
}
void ZombieFactory::addZombie(Zombie* newZombie) {
	Zombie** tmp = new Zombie * [numZombies + 1];
	for (int i = 0; i < numZombies; i++)
		tmp[i] = zombies[i];
	tmp[numZombies] = newZombie;
	delete[] zombies;
	zombies = tmp;
	numZombies++;
}
void ZombieFactory::removeZombie(int i) {
	cout << "zombie removed";
	delete zombies[i];
	zombies[i] = nullptr;
	if (numZombies > 1) {
		Zombie** tmp = new Zombie * [numZombies - 1];
		int j = 0;
		for (int i = 0; i < numZombies; i++) {
			if (zombies[i] != nullptr) {
				tmp[j++] = zombies[i];
			}
		}
		delete[] zombies;
		zombies = tmp;
	}
	else {
		delete[] zombies;
		zombies = nullptr;
	}
	numZombies--;
	cout << "num zombies: " << numZombies << endl;
}
void ZombieFactory::removeDeadZombies(int& levelScore) {
	for (int i = 0; i < numZombies; i++) {
		if (!zombies[i]->getIsAlive()) {
			levelScore += zombies[i]->getScore();
			removeZombie(i);
		}
	}
}
void ZombieFactory::move(double time) {
	for (int i = 0; i < numZombies; i++)
		zombies[i]->move(time);
}
void ZombieFactory::action(double time) {
	for (int i = 0; i < numZombies; i++)
		zombies[i]->action(time);

}
void ZombieFactory::draw(RenderWindow& window) {
	for (int i = 0; i < numZombies; i++)
		zombies[i]->draw(window);
}
Zombie* ZombieFactory::operator[](int index) {
	return zombies[index];
}
ZombieFactory::~ZombieFactory() {
	for (int i = 0; i < numZombies; i++)
		delete zombies[i];
	delete[] zombies;
}