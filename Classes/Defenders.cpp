#include "Defenders.h"

Defenders::Defenders() : defenders(nullptr), numDefenders(5) {
	defenders = new LaneDefender * [numDefenders];
	for (int i = 0; i < 5; i++)
		defenders[i] = new LaneDefender(16, i * 5.5 + 6);
}
int Defenders::getNumLawnmowers() {
	return numDefenders;
}
void Defenders::action() {
	for (int i = 0; i < numDefenders; i++) {
		if (defenders[i]->getVictim() != nullptr) {
			defenders[i]->attack();
		}
	}
}
void Defenders::removeDefender(int i) {
	delete defenders[i];
	defenders[i] = nullptr;
	LaneDefender** tmp = new LaneDefender * [numDefenders - 1];
	int j = 0;
	for (int i = 0; i < numDefenders; i++) {
		if (defenders[i] != nullptr) {
			tmp[j++] = defenders[i];
		}
	}
	delete[] defenders;
	defenders = tmp;
	numDefenders--;

}
void Defenders::move(double time) {
	for (int i = 0; i < numDefenders; i++) {
		if (defenders[i]->getSpeed() > 0) {
			defenders[i]->move(time);
			if (defenders[i]->position.x >= 60)
				removeDefender(i);
		}
	}
}
LaneDefender* Defenders::operator[](int index) {
	return defenders[index];
}
void Defenders::draw(RenderWindow& window) {
	for (int i = 0; i < numDefenders; i++)
		defenders[i]->draw(window);
}
Defenders::~Defenders() {
	for (int i = 0; i < numDefenders; i++)
		delete defenders[i];
	delete[] defenders;
}