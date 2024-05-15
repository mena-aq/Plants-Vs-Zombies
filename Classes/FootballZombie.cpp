#include "FootballZombie.h"

FootballZombie::FootballZombie(double x, double y, double time) : AttackerZombie(x, y, 3, 6, 120, 0.1, 20), changeDirectionTime(time), currentLane(laneCalculation()), targetLane(currentLane) { //double health
	this->texture.loadFromFile("../Images/footballzombie.png"); // 6 hits
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 98, 110));
}
bool FootballZombie::timeToSwitchLane(double time) {
	if (time - changeDirectionTime >= 5 && targetLane == currentLane) {
		return true;
	}
	return false;
}
void FootballZombie::switchLane() {
	int newLane = rand() % 5;
	while (newLane == currentLane)
		newLane = rand() % 5;
	targetLane = newLane;
}
void FootballZombie::move(double time) {
	if (timeToSwitchLane(time))
		switchLane();
	if (currentLane == targetLane) {
		position.x -= speed;
		collider.x -= speed;
	}
	else {
		if (currentLane < targetLane) {
			if (position.y < 5 + (targetLane * 5.5)) {
				position.y += speed;
				collider.y += speed;
			}
			else {
				currentLane = targetLane;
				changeDirectionTime = time;
			}
		}
		else {
			if (position.y > 5 + (targetLane * 5.5)) {
				position.y -= speed;
				collider.y -= speed;
			}
			else {
				currentLane = targetLane;
				changeDirectionTime = time;
			}
		}
	}
}
void FootballZombie::restoreSpeed() {
	this->speed = 0.1;
}