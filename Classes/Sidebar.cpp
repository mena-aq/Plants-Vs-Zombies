#include "Sidebar.h"

Sidebar::Sidebar(int level) {
	initialiseTextures();
	numButtons = level + 1;
	buttons = new InventoryButton * [numButtons];
	for (int i = 0; i < numButtons; i++) {
		buttons[i] = new InventoryButton(i / 5 * 6 + 1, 6 + (i % 5) * 5, 5, 5, 7);
		buttons[i]->setTexture(textures[i]);
		buttons[i]->setClickTexture(clickedTextures[i]);
		buttons[i]->setOffTexture(offTextures[i]);
		buttons[i]->setCooldown(cooldowns[i]);
	}
}
int Sidebar::getNumButtons() {
	return numButtons;
}
void Sidebar::initialiseTextures() {
	//normal
	textures[0].loadFromFile("../Images/peashooterpack.png");
	textures[1].loadFromFile("../Images/sunflowerpack.png");
	textures[2].loadFromFile("../Images/walnutpack.png");
	textures[3].loadFromFile("../Images/cherrybombpack.png");
	textures[4].loadFromFile("../Images/repeaterpack.png");
	textures[5].loadFromFile("../Images/snowpeapack.png");
	//clicked
	clickedTextures[0].loadFromFile("../Images/peashooterpack_clicked.png");
	clickedTextures[1].loadFromFile("../Images/sunflowerpack_clicked.png");
	clickedTextures[2].loadFromFile("../Images/walnutpack_clicked.png");
	clickedTextures[3].loadFromFile("../Images/cherrybombpack_clicked.png");
	clickedTextures[4].loadFromFile("../Images/repeaterpack_clicked.png");
	clickedTextures[5].loadFromFile("../Images/snowpeapack_clicked.png");
	//off
	offTextures[0].loadFromFile("../Images/peashooterpack2.png");
	offTextures[1].loadFromFile("../Images/sunflowerpack2.png");
	offTextures[2].loadFromFile("../Images/walnutpack2.png");
	offTextures[3].loadFromFile("../Images/cherrybombpack2.png");
	offTextures[4].loadFromFile("../Images/repeaterpack2.png");
	offTextures[5].loadFromFile("../Images/snowpeapack2.png");

}
void Sidebar::unClickAllButtons() {
	for (int i = 0; i < numButtons; i++)
		buttons[i]->unClick();
}
void Sidebar::unClickOtherButtons(int index) {
	for (int i = 0; i < numButtons; i++) {
		if (i != index && buttons[i]->isClicked())
			buttons[i]->unClick();
	}
}
void Sidebar::onClick(int boxX, int boxY, double time) {
	if ((boxY >= 7 && boxY <= 10) && (boxX >= 2 && boxX <= 6)) {
		unClickOtherButtons(0);
		buttons[0]->onClick(time);
	}
	else if ((boxY >= 12 && boxY <= 15) && (boxX >= 2 && boxX <= 6)) {
		unClickOtherButtons(1);
		buttons[1]->onClick(time);
	}
	else if ((boxY >= 17 && boxY <= 20) && (boxX >= 2 && boxX <= 6)) {
		unClickOtherButtons(2);
		buttons[2]->onClick(time);
	}
	else if ((boxY >= 22 && boxY <= 25) && (boxX >= 2 && boxX <= 6)) {
		unClickOtherButtons(3);
		buttons[3]->onClick(time);
	}
	else if ((boxY >= 27 && boxY <= 30) && (boxX >= 2 && boxX <= 6)) {
		unClickOtherButtons(4);
		buttons[4]->onClick(time);
	}
	else if ((boxY >= 7 && boxY <= 10) && (boxX >= 8 && boxX <= 12)) {
		unClickOtherButtons(5);
		buttons[5]->onClick(time);
	}
}
void Sidebar::refreshButtons(int money, double time) {
	for (int i = 0; i < numButtons; i++) {
		if (money < prices[i] || !buttons[i]->checkCoolDown(time)) //insifficnet money/cooldown wait
			buttons[i]->disable();
		else if (!buttons[i]->isEnabled()) //re-enable
			buttons[i]->enable();
	}
}
InventoryButton* Sidebar::operator[](int index) {
	return buttons[index];
}
void Sidebar::draw(RenderWindow& window) {
	for (int i = 0; i < numButtons; i++)
		buttons[i]->draw(window);
}
Sidebar::~Sidebar() {
	for (int i = 0; i < numButtons; i++)
		delete buttons[i];
	delete buttons;
}