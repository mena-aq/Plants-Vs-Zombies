#include "Position.h"
#include "BoxCollider.h"
#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef GameObject_H
#define GameObject_H

class GameObject {
protected:
	const int box = 16;
	bool exists;
	Texture texture;
	Sprite sprite;
public:
	Position position;
	BoxCollider collider;
	GameObject();
	GameObject(Position position, double w, double h);
	GameObject(double x, double y, double w, double h);
	bool getExists();
	void setPosition(double x, double y);
	virtual void draw(RenderWindow& window);
};

#endif