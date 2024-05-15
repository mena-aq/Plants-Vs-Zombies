#pragma once
#include "Character.h"

class Zombie;

#ifndef Plant_H
#define Plant_H
class Plant : public Character {
protected:
	int price;
	bool edible;
public:
	Plant();
	Plant(double x, double y, double w, double h, int price = 0, int health = 6);
	Plant(int price);
	Plant(int price, int health);
	int getPrice()const;
	bool isEdible()const;
	void deductPrice(int& money);
	virtual bool actionTime(double time) = 0;
	virtual void action(double time) = 0;
	virtual void checkCollision(Zombie* zombie) = 0;
	virtual void drawItems(RenderWindow& window) = 0;
	virtual ~Plant();

};
#endif
