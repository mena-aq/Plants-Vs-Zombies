#include "LevelScreen.h"

LevelScreen::LevelScreen(Player* player) :player(player) {
    if (!backgroundTexture.loadFromFile("../Images/menu2.png")) {
        cout << "Failed to load background image" << endl;
    }
    background.setTexture(backgroundTexture);
    if (!font.loadFromFile("../Fonts/virgo.ttf")) {
        cout << "Could not load font" << endl;
    }
    initialiseTextures();  
    initialiseButtons();  
    score.setFont(font);
    score.setCharacterSize(32);
    score.setFillColor(sf::Color::White);
    score.setPosition(790, 4);

    initializeText(backButton, "Back", 860, 480);
}
void LevelScreen::display_menu(RenderWindow& window) {
    bool onWindow = true;
    while (onWindow && window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            int mouseX = Mouse::getPosition(window).x;
            int mouseY = Mouse::getPosition(window).y;

            updateTextColor(backButton, mouseX, mouseY);
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                checkTextClick(backButton, mouseX, mouseY, 0, window, onWindow); // Assuming 0 is for going back to main menu
                checkButtonClick(Vector2f(mouseX, mouseY), window);
            }
        }
        std::ostringstream oss2;
        oss2 << "Score: " << player->getScore();
        this->score.setString(oss2.str());
        window.clear();
        window.draw(background);
        drawButtons(window);
        window.draw(backButton);
        window.draw(score);
        window.display();
    }
}
void LevelScreen::initialiseTextures() {
    //unlocked
    textures[0].loadFromFile("../Images/level1.png");
    textures[1].loadFromFile("../Images/level2.png");
    textures[2].loadFromFile("../Images/level3.png");
    textures[3].loadFromFile("../Images/level4.png");
    textures[4].loadFromFile("../Images/level5.png");
    textures[5].loadFromFile("../Images/level6.png");
    //locked
    lockedTextures[0].loadFromFile("../Images/level1_locked.png");
    lockedTextures[1].loadFromFile("../Images/level2_locked.png");
    lockedTextures[2].loadFromFile("../Images/level3_locked.png");
    lockedTextures[3].loadFromFile("../Images/level4_locked.png");
    lockedTextures[4].loadFromFile("../Images/level5_locked.png");
    lockedTextures[5].loadFromFile("../Images/level6_locked.png");
}
void LevelScreen::initialiseButtons() {
    for (int i = 0; i < 6; i++) {
        if (player->isLevelUnlocked(i + 1))
            buttons[i].enable();
        if (buttons[i].isEnabled())
            buttons[i].setTexture(textures[i]);
        else
            buttons[i].setTexture(lockedTextures[i]);
        buttons[i].setPosition(7 + i % 3 * 16, 3 + i / 3 * 15);
    }
}
void LevelScreen::checkButtonClick(Vector2f mousePosition, RenderWindow& window) {
    int levelsUnlocked = player->levelsUnlocked();
    for (int i = 0; i < 6; i++) {
        if (buttons[i].getSprite().getGlobalBounds().contains(mousePosition) && buttons[i].isEnabled()) {
            cout << "Clicked Level " << i + 1 << endl;
            int result;
            int levelScore;
            if (i == 0) {
                LevelOne level;
                result = level.playLevel(window);
                levelScore = level.getLevelScore();
                if (result == 1 && levelsUnlocked <= 1)
                    player->unlockLevel(2);
            }
            else if (i == 1) {
                LevelTwo level;
                result = level.playLevel(window);
                levelScore = level.getLevelScore();
                if (result == 1 && levelsUnlocked <= 2)
                    player->unlockLevel(3);
            }
            else if (i == 2) {
                LevelThree level;
                result = level.playLevel(window);
                levelScore = level.getLevelScore();
                if (result == 1 && levelsUnlocked <= 3)
                    player->unlockLevel(4);
            }
            else if (i == 3) {
                LevelFour level;
                result = level.playLevel(window);
                levelScore = level.getLevelScore();
                if (result == 1 && levelsUnlocked <= 3)
                    player->unlockLevel(4);
            }
            else if (i == 4) {
                LevelFive level;
                result = level.playLevel(window);
                levelScore = level.getLevelScore();
                if (result == 1 && levelsUnlocked <= 4)
                    player->unlockLevel(5);
            }
            if (result == 1 || result == 2) {
                player->updateScore(levelScore);
                GameOverMenu gameOverMenu(i + 1, levelScore, result);
                gameOverMenu.displayMenu(window);
            }
            unlockLevels();
            break;
        }
    }
}
void LevelScreen::unlockLevels() {
    int levelsUnlocked = player->levelsUnlocked();
    for (int i = 0; i < 6; i++) {
        if (player->isLevelUnlocked(i + 1))
            buttons[i].enable();
        if (buttons[i].isEnabled())
            buttons[i].setTexture(textures[i]);
    }
}
void LevelScreen::drawButtons(RenderWindow& window) {
    for (int i = 0; i < 6; i++)
        buttons[i].draw(window);
}
void LevelScreen::initializeText(Text& text, const string& str, float x, float y) {
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(30);
    text.setFillColor(normalColor);
    text.setPosition(x, y);
}
void LevelScreen::updateTextColor(Text& text, int mouseX, int mouseY) {
    if (text.getGlobalBounds().contains(mouseX, mouseY)) {
        text.setFillColor(hoverColor);
    }
    else {
        text.setFillColor(normalColor);
    }
}
void LevelScreen::checkTextClick(Text& text, int mouseX, int mouseY, int levels, RenderWindow& window, bool& onWindow) {
    if (text.getGlobalBounds().contains(mouseX, mouseY)) {
        onWindow = false;
    }
}