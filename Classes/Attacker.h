
#ifndef Attacker_H
#define Attacker_H

class Attacker {
protected:
	int damage;
public:
	Attacker(int damage=0);
	virtual void attack() = 0;
};


#endif
