#include "GameOverMenu.h"

GameOverMenu::GameOverMenu(int level, int levelScore, int winlose) {
	texture.loadFromFile("../Images/gameOverMenu.jpg");
	sprite.setTexture(texture);
	font.loadFromFile("../Fonts/virgo.ttf");

	message.setFont(font);
	message.setFillColor(Color::Black);
	message.setCharacterSize(50);
	message.setPosition(336, 32);
	if (winlose == 1)
		message.setString("LEVEL WON!");
	else
		message.setString("LEVEL LOST!");

	score.setFont(font);
	score.setCharacterSize(32);
	score.setFillColor(sf::Color::Black);
	score.setPosition(384, 96);
	std::ostringstream oss2;
	oss2 << "Score: " << levelScore;
	this->score.setString(oss2.str());

	backButton.setFont(font);
	backButton.setFillColor(Color::Black);
	backButton.setString("BACK TO LEVELS");
	backButton.setCharacterSize(30);
	backButton.setPosition(352, 352);

	reward.setPosition(384, 160);
	rewards[0].loadFromFile("../Images/reward1.png");
	rewards[1].loadFromFile("../Images/reward2.png");
	rewards[2].loadFromFile("../Images/reward3.png");
	rewards[3].loadFromFile("../Images/reward4.png");
	rewards[4].loadFromFile("../Images/reward5.png");
	reward.setTexture(rewards[level - 1]);
}
void GameOverMenu::displayMenu(RenderWindow& window) {
	bool onWindow = true;
	while (onWindow && window.isOpen()) {
		Event s;
		Vector2i mousePos = Mouse::getPosition(window);
		while (window.pollEvent(s))
		{
			if (s.type == Event::Closed)
				window.close();
			if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
				backButton.setFillColor(Color::Red);
			else
				backButton.setFillColor(Color::Black);
			if (s.type == Event::MouseButtonReleased && s.mouseButton.button == Mouse::Left) {
				int mouseX = s.mouseButton.x;
				int mouseY = s.mouseButton.y;
				if (backButton.getGlobalBounds().contains(mousePos.x, mousePos.y))
					onWindow = false;
			}
		}
		window.clear();
		window.draw(sprite);
		window.draw(message);
		window.draw(score);
		window.draw(reward);
		window.draw(backButton);
		window.display();
	}
}