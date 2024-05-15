#include "Plant.h"
#include "Zombie.h"

Plant::Plant() :Character(6), price(0), edible(true) {

}
Plant::Plant(double x, double y, double w, double h, int price, int health) : Character(x, y, w, h, health), price(price), edible(true) {

}
Plant::Plant(int price) :Character(6), price(price), edible(true) {

}
Plant::Plant(int price, int health) : Character(health), price(price),edible(true) {

}
int Plant::getPrice() const {
	return price;
}

bool Plant::isEdible() const {
	return edible;
}
void Plant::deductPrice(int& money) {
	money -= price;
}
Plant::~Plant() {}