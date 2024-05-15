#include <SFML/Graphics.hpp>
using namespace sf;

#ifndef Fog_H
#define Fog_H

class Fog {
private:
	Sprite sprite;
	Texture fogtexture;
public:
	Fog();
	void setPosition(float x, float y);
	void drawFog(RenderWindow& window);
};

#endif