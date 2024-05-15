#include "Player.h"


Player::Player(const std::string& playerName, int initialScore) : name(playerName), score(initialScore) {
    for (int i = 0; i < MAX_LEVELS; ++i) {
        unlockedLevels[i] = false;
    }
}
void Player::setName(const std::string& newName) {
    name = newName;
}
std::string Player::getName() const {
    return name;
}
void Player::setScore(int newScore) {
    score = newScore;
}
int Player::getScore() const {
    return score;
}
void Player::updateScore(int points) {
    score += points;
}
int Player::levelsUnlocked() {
    int levelsUnlocked = 0;
    for (int i = 0; i < MAX_LEVELS; ++i) {
        if (isLevelUnlocked(i + 1))
            levelsUnlocked++;
    }
    return levelsUnlocked;
}
void Player::unlockLevel(int level) {
    if (level > 0 && level <= MAX_LEVELS) {
        unlockedLevels[level - 1] = true;  // Level indices start at 0
    }
}
bool Player::isLevelUnlocked(int level) const {
    if (level > 0 && level <= MAX_LEVELS) {
        return unlockedLevels[level - 1];
    }
    return false;
}
void Player::reset() {
    score = 0;
    for (int i = 0; i < MAX_LEVELS; ++i) {
        unlockedLevels[i] = false;
    }
}