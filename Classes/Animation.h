#ifndef Animation_H
#define Animation_H

class Animation {
private:
	int currentFrame;
	int totalFrames;
	//speed and clock
public:
	Animation(int totalFrames=1): totalFrames(totalFrames),currentFrame(0){}
	bool animationOn() {
		currentFrame++;
		if (currentFrame <= 5) //total
			return true;
		return false;
	}
};

#endif
