#include "Button.h"
#include <iostream>
using namespace std;

#ifndef LevelButton_H
#define LevelButton_H

class LevelButton : public Button {
private:
	bool enabled;
	bool clicked;
public:
	LevelButton();
	LevelButton(double x, double y, double w, double h);
	void enable();
	Sprite getSprite();
	bool isClicked();
	bool isEnabled();
	void disable();
	virtual void onClick(double clickTime);
	void unClick();
};

#endif

