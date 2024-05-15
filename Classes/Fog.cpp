#include "Fog.h"

Fog::Fog() {
	fogtexture.loadFromFile("../Images/fog.png");
	sprite.setTexture(fogtexture);
}
void Fog::setPosition(float x, float y) {
	sprite.setPosition(x * 16, y * 16);
}
void Fog::drawFog(RenderWindow& window) {
	window.draw(sprite);
}