#include "Plant.h"
#include "Peashooter.h"
#include "Sunflower.h"
#include "CherryBomb.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "Walnut.h"

#ifndef PlantFactory_H
#define PlantFactory_H

class PlantFactory {
private:

	Plant** plants;
	int numPlants;

public:

	PlantFactory();
	int getNumPlants();
	void createPlant(int type, int lane, int cell, double time, int& money, SunlightFactory* sunlightFactory);
	void removePlant(int index);
	void removeDeadPlants();
	void action(double time);
	void draw(RenderWindow& window);
	void drawPlantItems(RenderWindow& window);
	Plant* operator[](int index);
	~PlantFactory();
};



#endif