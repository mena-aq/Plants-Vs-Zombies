#include "LaneDefender.h"

#ifndef Defender_H
#define Defender_H

class Defenders {
private:
	LaneDefender** defenders;
	int numDefenders;
public:
	Defenders();
	int getNumLawnmowers();
	void action();
	void removeDefender(int i);
	void move(double time);
	LaneDefender* operator[](int index);
	void draw(RenderWindow& window);
	~Defenders();
};


#endif
