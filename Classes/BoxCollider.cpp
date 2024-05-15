#include "BoxCollider.h"

BoxCollider::BoxCollider() :x(0), y(0), width(0), height(0), radius(0) {

}
BoxCollider::BoxCollider(double x, double y, double w, double h) : x(x), y(y), width(w), height(h), radius(0) {

}

bool BoxCollider::operator==(const BoxCollider& b2) {
	if ((b2.x >= this->x && b2.x <= this->x + this->width + this->radius) && (b2.y >= this->y - this->height - this->radius && b2.y <= this->y + this->height + this->radius))
		return true;
	if ((b2.x <= this->x && b2.x >= this->x - this->width - this->radius) && (b2.y >= this->y - this->height - this->radius && b2.y <= this->y + this->height + this->radius))
		return true;

	return false;

}
