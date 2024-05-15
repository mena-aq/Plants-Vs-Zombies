#pragma once
#include <string>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
private:
    std::string name;         // Player's name
    int score;                // Player's score
    static const int MAX_LEVELS = 6;  // Maximum number of levels
    bool unlockedLevels[MAX_LEVELS];    // Array to track unlocked levels

public:
 
    Player(const std::string& playerName = "", int initialScore = 0);
    void setName(const std::string& newName);
    std::string getName() const;
    void setScore(int newScore);
    int getScore() const;
    void updateScore(int points);
    int levelsUnlocked();
    void unlockLevel(int level);
    bool isLevelUnlocked(int level) const;
    void reset();
};

#endif 
