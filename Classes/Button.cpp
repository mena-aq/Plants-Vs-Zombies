#include "Button.h"

Button::Button() {}
Button::Button(double x, double y, double w, double h) : position(x, y), width(w), height(h) {}
void Button::setTexture(Texture& texture) {
	this->texture = texture;
	sprite.setTexture(texture);
}
void Button::setPosition(double x, double y) {
	position.x = x;
	position.y = y;
}
void Button::draw(RenderWindow& window) {
	sprite.setPosition(position.x * 16, position.y * 16);
	window.draw(sprite);
}