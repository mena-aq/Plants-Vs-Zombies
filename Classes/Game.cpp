#include "Game.h"
#include "Login.h"
#include "Player.h"
#include "Menu.h"

Game::Game() {}
void Game::playGame(RenderWindow& window) {
	Login login;
	Player thisPlayer = login.playerLogin(window);
	Menu mainMenu(&thisPlayer);
	mainMenu.display_menu(window);
	//update player in file
	login.playerLogout(&thisPlayer);
}