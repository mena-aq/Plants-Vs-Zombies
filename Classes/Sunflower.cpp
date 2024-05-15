#include "Sunflower.h"

Sunflower::Sunflower(double time, SunlightFactory* sunlightFactory) : sunlightFactory(sunlightFactory), latestSpawnTime(time) {
	this->setTexture();
}
Sunflower::Sunflower(double x, double y, double time, SunlightFactory* sunlightFactory) : Plant(x, y, 2, 1, 50), sunlightFactory(sunlightFactory), latestSpawnTime(time) {
	this->setTexture();
	cout << "radius " << collider.width << endl;
}
void Sunflower::setTexture() {
	this->texture.loadFromFile("../Images/sunflower.png");
	sprite.setTexture(this->texture);
	sprite.setTextureRect(IntRect(0, 0, 65, 74));
}
bool Sunflower::actionTime(double time) {
	if (time - latestSpawnTime >= 10) {
		latestSpawnTime = time + 5; //so after expiry you wait 10s
		return true;
	}
	return false;
}
void Sunflower::action(double time) {
	if (actionTime(time))
		sunlightFactory->spawnSun(position.x, position.y, latestSpawnTime - 5);
}
void Sunflower::drawItems(RenderWindow& window) {
	sunlightFactory->draw(window);
}
void Sunflower::checkCollision(Zombie* zombie) {
	//not yet
}