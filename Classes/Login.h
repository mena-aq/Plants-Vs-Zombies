#pragma once
#include "InputName.h"
#include "Player.h"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#ifndef Login_H
#define Login_H

class Login {
private:
	const int maxPlayers;
    int numPlayers;
    int currentPlayer;
    std::string* usernames;
    int* scores;
    int* levelsUnlocked;
public:
    Login();
    Player playerLogin(RenderWindow& window);
    void playerLogout(Player* player);
    void readPlayerData(const std::string& filename);
    void writePlayerData(const std::string& filename);
    int findUser(string username);
};

#endif
