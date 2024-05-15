#include "LevelButton.h"

LevelButton::LevelButton() :enabled(false), clicked(false) {}
LevelButton::LevelButton(double x, double y, double w, double h) : Button(x, y, w, h), enabled(true), clicked(false) {}
void LevelButton::enable() {
	cout << "enabled";
	enabled = true;
}
Sprite LevelButton::getSprite() {
	return sprite;
}
bool LevelButton::isClicked() {
	return clicked;
}
bool LevelButton::isEnabled() {
	return enabled;
}
void LevelButton::disable() {
	enabled = false;
}
void LevelButton::onClick(double clickTime) {
	if (enabled) {
		if (!clicked) {
			clicked = true;
			//sprite.setTexture(clickTexture);
		}
		else {
			clicked = false;
			sprite.setTexture(texture);
		}
	}
}
void LevelButton::unClick() {
	clicked = false;
	sprite.setTexture(texture);
}