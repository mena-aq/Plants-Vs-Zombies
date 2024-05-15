#include "LevelFour.h"

LevelFour::LevelFour() : Level(4, 18) {
	for (int i = 0; i < 5; i++) {
		fog[i].setPosition(35, i * 5.5);
	}
}
void LevelFour::handleInput(RenderWindow& window, bool& gameOn) {
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
			if ((pixelX >= 2 && pixelX <= 5) && (pixelY >= 7 && pixelY <= 30)) {
				sidebar.onClick(pixelX, pixelY, time);
			}
			bool collectedSun = collectSun(pixelX, pixelY);
			if (!collectedSun && pixelX >= 20 && pixelY >= 5)
				placePlant(laneCalculation(pixelY), cellCalculation(pixelX), time);
		}

	}
}
void LevelFour::drawLevel(RenderWindow& window) {
	createBack(window);
	plantFactory->draw(window);
	zombieFactory->draw(window);
	plantFactory->drawPlantItems(window);
	defenders->draw(window);
	sunlightFactory->draw(window);
	for (int i = 0; i < 5; i++)
		fog[i].drawFog(window);
	sidebar.draw(window);
	displayMoney(window);
}