#include "GameObject.h"

GameObject::GameObject() : exists(true) {
	texture.loadFromFile("../Images/defaultObject.png");
	sprite.setTexture(texture);
}
GameObject::GameObject(Position position, double w, double h) : position(position), collider(position.x, position.y, w, h), exists(true) {
	texture.loadFromFile("../Images/defaultObject.png");
	sprite.setTexture(texture);
	sprite.setOrigin((w / 2) * 16, (h / 2) * 16);
}
GameObject::GameObject(double x, double y, double w, double h) : position(x, y), collider(position.x, position.y, w, h), exists(true) {
	texture.loadFromFile("../Images/defaultObject.png");
	sprite.setTexture(texture);
	sprite.setOrigin((w / 2) * 16, (h / 2) * 16);
}
bool GameObject::getExists() {
	return exists;
}
void GameObject::setPosition(double x, double y) {
	position.x = x;
	position.y = y;
}
void GameObject::draw(RenderWindow& window) {
	sprite.setPosition(position.x * box, position.y * box);
	window.draw(sprite);
}