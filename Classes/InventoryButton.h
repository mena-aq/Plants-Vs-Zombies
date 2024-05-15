#include "Button.h"

#ifndef InventoryButton_H
#define InventoryButton_H

class InventoryButton : public Button {
private:
	double cooldown;
	double clickTime;
	bool enabled;
	bool clicked; 
	int price;
	Texture clickTexture;
	Texture offTexture;
public:
	InventoryButton(double x, double y, double w, double h, double cooldown);
	void enable();
	void setCooldown(double cooldown);
	void setPrice(int price);
	void setClickTexture(Texture& clickTexture);
	void setOffTexture(Texture& offTexture);
	bool isClicked();
	bool isEnabled();
	bool checkCoolDown(double time);
	void disable();
	virtual void onClick(double clickTime);
	void recharge(double time);
	void unClick();
};

#endif
