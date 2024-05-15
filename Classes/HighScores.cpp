#include "HighScores.h"
#include <sstream>
using namespace std;

HighScoreScreen::HighScoreScreen() {
    timer = 0;
    selected = -1;
    music_flag = false;
    tex.loadFromFile("../Images/leaderboard.png");
    ins.setTexture(tex);
    srand(time(0));

    if (!font.loadFromFile("../Fonts/virgo.ttf")) {
        cout << "could not load font" << endl;
    }
}

void HighScoreScreen::display_menu(RenderWindow& window) {
    int scores[5] = { 0, 0, 0,0 };
    string names[5] = { "xxx", "xxx", "xxx", "xxx" , "xxx" };
    ifstream inFile("../Data/scores.txt");

    int score;
    int count = 0;
    string name;
    string line;
    while (getline(inFile, line) && count < 3) {
        istringstream iss(line);
        if (iss >> name >> score) {
            scores[count] = score;
            names[count] = name;
            count++;
        }
    }
    //sort
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (scores[i] < scores[j]) {
                string tmpN;
                int tmpS;
                tmpS = scores[i];
                scores[i] = scores[j];
                scores[j] = tmpS;
                tmpN = names[i];
                names[i] = names[j];
                names[j] = tmpN;

            }
        }
    }

    for (int i = 0; i < 5; i++) {
        txt[2 * i].setFont(font);
        txt[2 * i].setFillColor(Color::Blue);
        txt[2 * i].setString(names[i]);
        txt[2 * i].setCharacterSize(30);
        txt[2 * i].setPosition(320, 150 + 70 * i);

        txt[2 * i + 1].setFont(font);
        txt[2 * i + 1].setFillColor(Color::Black);
        txt[2 * i + 1].setString(to_string(scores[i]));
        txt[2 * i + 1].setCharacterSize(30);
        txt[2 * i + 1].setPosition(640, 150 + 70 * i);
    }

    txt[11].setFont(font);
    txt[11].setFillColor(Color::Black);
    txt[11].setString("BACK");
    txt[11].setCharacterSize(30);
    txt[11].setPosition(860, 480);

    Event s;
    bool onWindow = true;
    while (onWindow && window.isOpen()) {
        Vector2i mousePos = Mouse::getPosition(window); // Get the position of the mouse relative to the window

        while (window.pollEvent(s)) {
            if (s.type == Event::Closed) // If cross/close is clicked/pressed
                window.close();

            // Handling mouse movement
            if (txt[11].getGlobalBounds().contains(mousePos.x, mousePos.y))
                txt[11].setFillColor(Color::Red);
            else
                txt[11].setFillColor(Color::Black);

            // Handling mouse clicks
            if (s.type == Event::MouseButtonReleased && s.mouseButton.button == Mouse::Left) {
                if (txt[11].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    onWindow = false; // Exit the high score screen
                }
            }
        }

        window.clear(Color::Black); // Clears the screen
        window.draw(ins); // Draws the background
        for (int i = 0; i < size; i++)
            window.draw(txt[i]);

        window.display();
    }
}