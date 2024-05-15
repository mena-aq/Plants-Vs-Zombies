#include "Login.h"

Login::Login() :maxPlayers(5), usernames(new std::string[maxPlayers]), scores(new int[maxPlayers]), levelsUnlocked(new int[maxPlayers]), numPlayers(0), currentPlayer(-1) {}
Player Login::playerLogin(RenderWindow& window) {
    InputName* playermenu = new InputName; //set player data in this
    std::string username = playermenu->display_menu(window);
    delete playermenu;
    cout << username << endl;
    readPlayerData("../Data/scores.txt");
    currentPlayer = findUser(username);
    Player player(usernames[currentPlayer], scores[currentPlayer]);
    for (int i = 0; i < 6; i++) {
        if (i + 1 <= levelsUnlocked[currentPlayer])
            player.unlockLevel(i + 1);
    }
    cout << player.levelsUnlocked();
    return player;
}
void Login::playerLogout(Player* player) {
    scores[currentPlayer] = player->getScore();;
    levelsUnlocked[currentPlayer] = player->levelsUnlocked();
    writePlayerData("../Data/scores.txt");
}
void Login::readPlayerData(const std::string& filename) {
    std::ifstream file(filename);
    numPlayers = 0;
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line) && numPlayers < maxPlayers) {
            std::istringstream iss(line);
            if (iss >> usernames[numPlayers] >> scores[numPlayers] >> levelsUnlocked[numPlayers])
                numPlayers++;
        }
        file.close();
    }
}
void Login::writePlayerData(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < numPlayers; i++) {
            file << usernames[i] << " " << scores[i] << " " << levelsUnlocked[i] << "\n";
        }
        file.close();
    }
}
int Login::findUser(string username) {
    bool found = false;
    for (int i = 0; i < numPlayers; i++) {
        if (usernames[i] == username) {
            std::cout << "Player found! Username: " << usernames[i] << ", Score: " << scores[i] << ", levels: " << levelsUnlocked[i] << std::endl;
            return i;
        }
    }
    if (!found) {
        std::cout << "Player not found. Creating new player..." << std::endl;
        if (numPlayers < maxPlayers) {
            usernames[numPlayers] = username;
            scores[numPlayers] = 0;
            levelsUnlocked[numPlayers] = 1;
            numPlayers++;
            return numPlayers - 1;
        }
        else {
            std::cerr << "Maximum number of players reached." << std::endl;
        }
    }
    return 0;
}