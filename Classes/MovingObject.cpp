#include "MovingObject.h"

MovingObject::MovingObject(double speed) :speed(speed) {

}
double MovingObject::getSpeed() {
	return speed;
}
void MovingObject::updateSpeed(double factor) {
	speed *= factor;
}
