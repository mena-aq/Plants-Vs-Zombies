#include "InventoryButton.h"

InventoryButton::InventoryButton(double x, double y, double w, double h, double cooldown) : Button(x, y, w, h), cooldown(cooldown), clickTime(-8), enabled(true), clicked(false), price(0) {}
void InventoryButton::enable() {
	sprite.setTexture(texture);
	enabled = true;
}
void InventoryButton::setCooldown(double cooldown) {
	this->cooldown = cooldown;
}
void InventoryButton::setPrice(int price) {
	this->price = price;
}
void InventoryButton::setClickTexture(Texture& clickTexture) {
	this->clickTexture = clickTexture;
}
void InventoryButton::setOffTexture(Texture& offTexture) {
	this->offTexture = offTexture;
}
bool InventoryButton::isClicked() {
	return clicked;
}
bool InventoryButton::isEnabled() {
	return enabled;
}
bool InventoryButton::checkCoolDown(double time) {
	if (time - clickTime >= cooldown)
		return true;
	return false;
}
void InventoryButton::disable() {
	sprite.setTexture(offTexture);
	enabled = false;
}
void InventoryButton::onClick(double clickTime) {
	if (enabled) {
		if (!clicked) {
			clicked = true;
			sprite.setTexture(clickTexture);
		}
		else {
			clicked = false;
			sprite.setTexture(texture);
		}
	}
}
void InventoryButton::recharge(double time) {
	this->clickTime = time;
	this->disable();
}
void InventoryButton::unClick() {
	clicked = false;
	sprite.setTexture(texture);
}