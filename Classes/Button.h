#include "Position.h"
#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef Button_H
#define Button_H

class Button {
protected:
	Position position;
	Texture texture;
	Sprite sprite;
	double width;
	double height;
public:
	Button();
	Button(double x, double y, double w, double h);
	virtual void onClick(double clickTime) = 0;
	void setTexture(Texture& texture);
	void setPosition(double x, double y);
	void draw(RenderWindow& window);
};


#endif