#include "InventoryButton.h"

#ifndef Sidebar_H
#define Sidebar_H

class Sidebar {
private:
	InventoryButton** buttons;
	Texture textures[6];  
	Texture clickedTextures[6];
	Texture offTextures[6];
	int prices[6] = { 100,50,50,150,150,175};
	double cooldowns[6] = { 7.5,7.5,7.5,7.5,7.5,7.5 };
	int numButtons;
public:
	Sidebar(int level);
	int getNumButtons();
	void initialiseTextures();
	void unClickAllButtons();
	void unClickOtherButtons(int index);
	void onClick(int boxX, int boxY, double time);
	void refreshButtons(int money, double time);
	InventoryButton* operator[](int index);
	void draw(RenderWindow& window);
	~Sidebar();
};

#endif
