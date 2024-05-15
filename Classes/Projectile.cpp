#include "Projectile.h"

Projectile::Projectile() : victim(nullptr), expired(false) {}
Projectile::Projectile(Position position, double w, double h, double speed, int damage) :GameObject(position, w, h), MovingObject(speed), Attacker(damage), victim(nullptr), expired(false) {

}
Projectile::Projectile(double x, double y, double w, double h, double speed, int damage) :GameObject(x, y, w, h), MovingObject(speed), Attacker(damage), victim(nullptr), expired(false) {

}
bool Projectile::getExpired() {
	return this->expired;
}
void Projectile::move(double time) {
	position.x += speed;
	collider.x += speed;
}
Zombie* Projectile::getVictim() {
	return victim;
}
bool Projectile::isVictimAttached() {
	if (victim == nullptr)
		return false;
	return true;
}
void Projectile::attachVictim(Zombie* victim) {
	this->victim = victim;
}
void Projectile::attack() {
	if (this->victim != nullptr) {
		this->victim->updateHealth(this->damage);
		this->detachVictim();
	}
}
void Projectile::detachVictim() {
	this->victim = nullptr;
	expired = true;
	this->updateSpeed(0);
}
void Projectile::draw(RenderWindow& window) {
	if (!expired || expired && animation.animationOn()) {
		sprite.setPosition(position.x * box, position.y * box);
		window.draw(sprite);
	}
	else
		this->exists = false;
}
void Projectile::checkCollision(GameObject* object) {

}