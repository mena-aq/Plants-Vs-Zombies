#include "LevelFive.h"

LevelFive::LevelFive() : Level(5, 24) {}
void LevelFive::handleInput(RenderWindow& window, bool& gameOn) {
	sidebar.refreshButtons(money, time);
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed) {
			int pixelX = (event.mouseButton.x) / 16 + 1;
			int pixelY = (event.mouseButton.y) / 16 + 1;
			if ((pixelX >= 54 && pixelX <= 55) && (pixelY >= 2 && pixelY <= 3)) {
				levelClock.pause();
				Pause* pausemenu = new Pause;
				pausemenu->display_menu(window, gameOn);
				levelClock.start();
			}
			if ((pixelX >= 57 && pixelX <= 58) && (pixelY >= 2 && pixelY <= 3)) {
				playerResult = 3;
				gameOn = false;
			}
			if ((pixelX >= 2 && pixelX <= 12) && (pixelY >= 7 && pixelY <= 30))
				sidebar.onClick(pixelX, pixelY, time);

			bool collectedSun = collectSun(pixelX, pixelY);
			if (!collectedSun && pixelX >= 20 && pixelY >= 5)
				placePlant(laneCalculation(pixelY), cellCalculation(pixelX), time);
		}

	}
}
