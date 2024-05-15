#include "LevelOne.h"

LevelOne::LevelOne() : Level(1, 5) {}
void LevelOne::handleInput(RenderWindow& window, bool& gameOn) {
	sidebar.refreshButtons(money, time);
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed) {
			int pixelX = (event.mouseButton.x) / 16 + 1;
			int pixelY = (event.mouseButton.y) / 16 + 1;
			// pause button
			if ((pixelX >= 54 && pixelX <= 55) && (pixelY >= 2 && pixelY <= 3)) {
				levelClock.pause();
				Pause* pausemenu = new Pause;
				pausemenu->display_menu(window, gameOn);
				levelClock.start();
			}
			if ((pixelX >= 57 && pixelX <= 58) && (pixelY >= 2 && pixelY <= 3)) {
				cout << "quit";
				playerResult = 3;
				gameOn = false;
			}
			if ((pixelX >= 2 && pixelX <= 7) && (pixelY >= 7 && pixelY <= 20))
				sidebar.onClick(pixelX, pixelY, time);
			bool collectedSun = collectSun(pixelX, pixelY);
			if (!collectedSun && pixelX >= 20 && pixelY >= 5)
				placePlant(laneCalculation(pixelY), cellCalculation(pixelX), time);
		}

	}
}