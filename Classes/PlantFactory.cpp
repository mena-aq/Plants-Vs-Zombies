#include "PlantFactory.h"


PlantFactory::PlantFactory() : plants(nullptr), numPlants(0) {}
int PlantFactory::getNumPlants() {
	return numPlants;
}
void PlantFactory::createPlant(int type, int lane, int cell, double time, int& money, SunlightFactory* sunlightFactory) {
	Plant* newPlant = nullptr;
	//based on type
	if (type == 1)
		newPlant = new Peashooter(20.5 + cell * 4.5, 5 + (lane * 5.5));
	else if (type == 2)
		newPlant = new Sunflower(20.5 + cell * 4.5, 5 + (lane * 5.5), time, sunlightFactory);
	else if (type == 3)
		newPlant = new Walnut(20.5 + cell * 4.5, 5 + (lane * 5.5), time);
	else if (type == 4)
		newPlant = new CherryBomb(20.5 + cell * 4.5, 5 + (lane * 5.5), time);
	else if (type == 5)
		newPlant = new Repeater(20.5 + cell * 4.5, 5 + (lane * 5.5));
	else if (type == 6)
		newPlant = new SnowPea(20.5 + cell * 4.5, 5 + (lane * 5.5));
	newPlant->deductPrice(money);
	///
	Plant** tmp = new Plant * [numPlants + 1];
	for (int i = 0; i < numPlants; i++)
		tmp[i] = plants[i];
	tmp[numPlants] = newPlant;
	delete[] plants;
	plants = tmp;
	numPlants++;
}
void PlantFactory::removePlant(int index) {
	cout << "plant removed";
	delete plants[index];
	plants[index] = nullptr;
	Plant** tmp = new Plant * [numPlants - 1];
	int j = 0;
	for (int i = 0; i < numPlants; i++) {
		if (plants[i] != nullptr) {
			tmp[j++] = plants[i];
		}
	}
	delete[] plants;
	plants = tmp;
	numPlants--;
}
void PlantFactory::removeDeadPlants() {
	for (int i = 0; i < numPlants; i++) {
		if (!plants[i]->getIsAlive())
			removePlant(i);
	}
}
void PlantFactory::action(double time) {
	for (int i = 0; i < numPlants; i++)
		plants[i]->action(time);
}
void PlantFactory::draw(RenderWindow& window) {
	for (int i = 0; i < numPlants; i++)
		plants[i]->draw(window);
}
void PlantFactory::drawPlantItems(RenderWindow& window) {
	for (int i = 0; i < numPlants; i++)
		plants[i]->drawItems(window);
}
Plant* PlantFactory::operator[](int index) {
	return plants[index];
}
PlantFactory::~PlantFactory() {
	for (int i = 0; i < numPlants; i++)
		delete plants[i];
	delete[] plants;
}