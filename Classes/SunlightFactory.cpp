#include "SunlightFactory.h"

SunlightFactory::SunlightFactory(double time) :sunlight(nullptr), numSuns(0), latestSpawnTime(time),spawnInterval(15) {}
bool SunlightFactory::actionTime(double time) {
	if (time - latestSpawnTime >= spawnInterval) {
		latestSpawnTime = time;
		return true;
	}
	return false;
}
int SunlightFactory::getNumSuns() {
	return numSuns;
}
double SunlightFactory::getLatestSpawnTime() {
	return latestSpawnTime;
}
void SunlightFactory::setSpawnInterval(double interval) {
	this->spawnInterval = interval;
}
void SunlightFactory::action(double time) { //sky one
	if (actionTime(time))
		spawnSun(rand() % 40 + 20, 0);
	fall(time);
	removeExpiredSuns(time);
}
void SunlightFactory::spawnSun(double x, double y, double sunflowerLatestSpawnTime) { //sunflower
	cout << "spawn sun from sunflower";
	Sunlight** tmp = new Sunlight * [numSuns + 1];
	for (int i = 0; i < numSuns; i++)
		tmp[i] = sunlight[i];
	tmp[numSuns] = new Sunlight(x, y, sunflowerLatestSpawnTime, 0);
	delete[] sunlight;
	sunlight = tmp;
	numSuns++;
}
void SunlightFactory::spawnSun(double x, double y) { //sky
	Sunlight** tmp = new Sunlight * [numSuns + 1];
	for (int i = 0; i < numSuns; i++)
		tmp[i] = sunlight[i];
	tmp[numSuns] = new Sunlight(x, y, latestSpawnTime, 0.25);
	delete[] sunlight;
	sunlight = tmp;
	numSuns++;
}
void SunlightFactory::removeSun(int i) {
	delete sunlight[i];
	sunlight[i] = nullptr;
	Sunlight** tmp = new Sunlight * [numSuns - 1];
	int j = 0;
	for (int i = 0; i < numSuns; i++) {
		if (sunlight[i] != nullptr) {
			tmp[j++] = sunlight[i];
		}
	}
	delete[] sunlight;
	sunlight = tmp;
	numSuns--;
}
void SunlightFactory::removeExpiredSuns(double moneyTime) {
	for (int i = 0; i < numSuns; i++) {
		sunlight[i]->checkExpire(moneyTime);
		if (!(sunlight[i]->getExists())) {
			removeSun(i);
		}
	}
}
void SunlightFactory::fall(double time) {
	for (int i = 0; i < numSuns; i++) {
		if (sunlight[i]->position.y >= 31) {
			removeSun(i);
		}
		else
			sunlight[i]->move(time);
	}
}
Sunlight* SunlightFactory::operator[](int index) {
	return sunlight[index];
}
void SunlightFactory::draw(RenderWindow& window) {
	for (int i = 0; i < numSuns; i++)
		sunlight[i]->draw(window);
}
SunlightFactory::~SunlightFactory() {
	for (int i = 0; i < numSuns; i++)
		delete sunlight[i];
	delete[] sunlight;
}