#include <SFML/Graphics.hpp>
using namespace sf;
#include <sstream>
using namespace std;

#ifndef GameOverMenu_H
#define GameOverMenu_H

class GameOverMenu {
private:
	Sprite sprite;
	Texture texture;
	Sprite reward;
	Texture rewards[5];
	Text backButton;
	Text message;
	Text score;
	Font font;
public:
	GameOverMenu(int level, int levelScore, int winlose);
	void displayMenu(RenderWindow& window);
};

#endif
