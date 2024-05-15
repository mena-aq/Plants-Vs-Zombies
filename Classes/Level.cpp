#include "Level.h"

Level::Level(int levelNum, int totalZombies) :levelNum(levelNum), totalZombies(totalZombies), zombiesGenerated(0), livesLeft(3), money(100), playerResult(false), levelScore(0), sidebar(levelNum), zombieFactory(nullptr), plantFactory(nullptr), sunlightFactory(nullptr), defenders(new Defenders), time(0) {
	font.loadFromFile("../Fonts/virgo.ttf");
	sunCount.setFont(font);
	sunCount.setCharacterSize(32);
	sunCount.setFillColor(sf::Color::Black);
	sunCount.setPosition(16 * 5, 16 * 1.25);
	score.setFont(font);
	score.setCharacterSize(28);
	score.setFillColor(sf::Color::Black);
	score.setPosition(220, 12);
}
int Level::getLevelScore() {
	return levelScore;
}
int Level::playLevel(RenderWindow& window) {

	levelClock.reset();

	initialiseFactories();

	bool quit = false;
	bool gameOn = true;
	while (gameOn && window.isOpen()) {
		time = levelClock.getTime();
		refreshLawn();
		handleInput(window, gameOn);
		if (!gameOn)
			break;
		updateState();
		//check win lose
		gameOn = checkProgress();
		window.clear();
		drawLevel(window);
		window.display();
	}
	exitLevel();
	return playerResult;
}
void Level::initialiseFactories() {
	plantFactory = new PlantFactory;
	zombieFactory = new ZombieFactory(time);
	if (levelNum == 2)
		zombieFactory->setSpawnInterval(12);
	if (levelNum == 3)
		zombieFactory->setSpawnInterval(10);
	if (levelNum == 4)
		zombieFactory->setSpawnInterval(9);
	if (levelNum == 5)
		zombieFactory->setSpawnInterval(8);
	sunlightFactory = new SunlightFactory(time);
	if (levelNum == 5)
		sunlightFactory->setSpawnInterval(7);
}
void Level::checkCollisions() {
	//collide 
	// projectiles-zmobie
	for (int i = 0; i < plantFactory->getNumPlants(); i++) {
		for (int j = 0; j < zombieFactory->getNumZombies(); j++) {
			((*plantFactory)[i])->checkCollision((*zombieFactory)[j]);
		}
	}
	//zombie-plant
	for (int i = 0; i < zombieFactory->getNumZombies(); i++) {
		for (int j = 0; j < plantFactory->getNumPlants(); j++)
			(*zombieFactory)[i]->checkCollision((*plantFactory)[j]);
	}
	//zombie-lawnmower
	for (int i = 0; i < defenders->getNumLawnmowers(); i++) {
		for (int j = 0; j < zombieFactory->getNumZombies(); j++)
			(*defenders)[i]->checkCollision((*zombieFactory)[j]);
	}
	//zombieFactory->zombieCollisionQueue(); //zombie-zombie
}
void Level::updateState() {
	//spawn
	if (zombieFactory->spawnZombie(time) && zombiesGenerated < totalZombies) {
		zombieFactory->createZombie(levelNum, time);
		zombiesGenerated++;
	}
	//move
	zombieFactory->move(time);
	defenders->move(time);
	//collisions
	checkCollisions();
	//action (e.g. attack, fire)
	plantFactory->action(time);
	zombieFactory->action(time);
	sunlightFactory->action(time);
	defenders->action();
	//remove dead chars
	zombieFactory->removeDeadZombies(levelScore);
	plantFactory->removeDeadPlants();
}
bool Level::placePlant(int lane, int cell, double time) {
	int i = 0;
	for (i = 0; i < sidebar.getNumButtons(); i++) {
		if (sidebar[i]->isClicked() && sidebar[i]->isEnabled())
			break;
	}
	if (i < sidebar.getNumButtons()) {
		if (board.isAvailable(lane, cell)) {
			plantFactory->createPlant(i + 1, lane, cell, time, money, sunlightFactory);
			board.makeUnavailable(lane, cell);
			sidebar[i]->recharge(time);
			sidebar.unClickAllButtons();
		}
	}
	return true;
}
bool Level::collectSun(int pixelX, int pixelY) {
	for (int i = 0; i < sunlightFactory->getNumSuns(); i++) {
		if ((pixelX >= (*sunlightFactory)[i]->position.x - 1 && pixelX <= (*sunlightFactory)[i]->position.x + 1) && (pixelY >= (*sunlightFactory)[i]->position.y - 1 && pixelY <= (*sunlightFactory)[i]->position.y + 1)) {
			money += 25;
			sunlightFactory->removeSun(i);
			return true;
		}
	}
	return false;
}
void Level::refreshLawn() {
	board.makeAllAvailable();
	for (int i = 0; i < plantFactory->getNumPlants(); i++) {
		int lane = (*plantFactory)[i]->laneCalculation();
		int cell = (*plantFactory)[i]->cellCalculation();
		board.makeUnavailable(lane, cell);
	}
}
bool Level::checkProgress() {
	if (winLevel() || loseLevel())
		return false;
	return true;
}
void Level::exitLevel() {
	delete plantFactory;
	delete zombieFactory;
	delete sunlightFactory;
	delete defenders;
}
bool Level::winLevel() {
	if (zombiesGenerated == totalZombies && zombieFactory->getZombies() == nullptr) {
		cout << "\nWON LEVEL\n";
		playerResult = 1;
		return true;
	}
	return false;
}
bool Level::loseLevel() {
	for (int i = 0; i < zombieFactory->getNumZombies(); i++) {
		if ((*zombieFactory)[i]->position.x <= 14) {
			cout << "\nlost level\n";
			playerResult = 2;
			return true;
		}
	}
	return false;
}
void Level::displayMoney(RenderWindow& window) {
	std::ostringstream oss2;
	oss2 << money;
	sunCount.setString(oss2.str());
	window.draw(sunCount);
}
void Level::displayScore(RenderWindow& window) {
	std::ostringstream oss2;
	oss2 << "Score: " << levelScore;
	this->score.setString(oss2.str());
	window.draw(score);
}
void Level::createBack(RenderWindow& window) {
	//Drawing the background
	Texture daymap, nightmap;
	daymap.loadFromFile("../Images/lawn_day.png");
	nightmap.loadFromFile("../Images/lawn_night.png");
	Sprite s_map;
	if (levelNum <= 3)
		s_map.setTexture(daymap);
	else
		s_map.setTexture(nightmap);
	s_map.scale(1.0f, 1.0f);
	s_map.setPosition(0, 0);
	window.draw(s_map);
}
void Level::drawLevel(RenderWindow& window) {
	createBack(window);
	plantFactory->draw(window);
	zombieFactory->draw(window);
	plantFactory->drawPlantItems(window);
	defenders->draw(window);
	sunlightFactory->draw(window);
	sidebar.draw(window);
	displayMoney(window);
	displayScore(window);
}
int Level::cellCalculation(double x) {
	int cellX = 0;
	if (x >= 20 && x <= 59.5)
		cellX = (x - 20) / 4.5;
	return cellX;
}
int Level::laneCalculation(double y) {
	int cellY = 0;
	if (y >= 5 && y <= 32)
		cellY = (y - 5) / 5.5;
	return cellY;
}
