#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef BoxCollider_H
#define BoxCollider_H

struct BoxCollider {
	double x;
	double y;
	double width;
	double height;
	double radius;
	BoxCollider();
	BoxCollider(double x, double y, double w, double h);
	virtual bool operator==(const BoxCollider& b2);
};


#endif