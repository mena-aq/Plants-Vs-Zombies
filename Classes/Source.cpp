// Menahil Ahmad (23i-0546) and Hania Waheed(22i-0982)

#include <SFML/Graphics.hpp>
using namespace sf;
#include "Game.h"
#include <ctime>
using namespace std;

int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(960, 528), "Plants Vs Zombies");
	//Game icon
	Image icon;
	if (!icon.loadFromFile("../Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());


	while (window.isOpen())
	{
		Game game;
		game.playGame(window);
	}
	return 0;
}



