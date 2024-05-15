#include "Pause.h"

Pause::Pause() {
    // Load resources
    if (!backgroundTexture.loadFromFile("../Images/pausemenu.png")) {
        cout << "Failed to load background image for Level Four" << endl;
    }
    background.setTexture(backgroundTexture);

    if (!font.loadFromFile("../Fonts/virgo.ttf")) {
        cout << "Could not load font" << endl;
    }

    pause_menu[0].setFont(font);
    pause_menu[0].setFillColor(Color::Black);
    pause_menu[0].setString("Resume");
    pause_menu[0].setCharacterSize(30);
    pause_menu[0].setPosition(400, 100);

    pause_menu[1].setFont(font);
    pause_menu[1].setFillColor(Color::Black);
    pause_menu[1].setString("Options");
    pause_menu[1].setCharacterSize(30);
    pause_menu[1].setPosition(400, 200);

    pause_menu[2].setFont(font);
    pause_menu[2].setFillColor(Color::Black);
    pause_menu[2].setString("Quit");
    pause_menu[2].setCharacterSize(30);
    pause_menu[2].setPosition(400, 300);

    //hoverbuffer.loadFromFile("sounds/effects/zap1.mp3");
    //hoversound.setBuffer(hoverbuffer);
    //hoversound.setVolume(100);

    //selectbuffer.loadFromFile("sounds/effects/zap2.ogg");
    //selectsound.setBuffer(selectbuffer);
    //selectsound.setVolume(100);

    //music.openFromFile("sounds/Title_Screen.ogg");
    //music.setVolume(20);
    //music.setLoop(true);

    selected = -1;
    musicFlag = true;
    exit = false;
}

void Pause::display_menu(RenderWindow& window, bool& gameOn) {
    bool onWindow = true;
    Clock timePaused;
    while (onWindow && window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            int mouseX = Mouse::getPosition(window).x;
            int mouseY = Mouse::getPosition(window).y;

            for (int i = 0; i < 3; i++) {
                if (pause_menu[i].getGlobalBounds().contains(mouseX, mouseY)) {
                    pause_menu[i].setFillColor(Color::Red);
                }
                else {
                    pause_menu[i].setFillColor(Color::Black);
                }
            }

            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 3; i++) {
                    if (pause_menu[i].getGlobalBounds().contains(mouseX, mouseY)) {
                        // selectsound.play();
                        executeAction(i, window, onWindow, gameOn);
                        break;
                    }
                }
            }
        }
        window.clear(Color::Black);
        window.draw(background);
        for (int i = 0; i < 3; i++) {
            window.draw(pause_menu[i]);
        }
        window.display();
    }
}

void Pause::executeAction(int index, RenderWindow& window, bool& onWindow, bool& gameOn) {
    switch (index) {
    case 0: // Resume 
        onWindow = false;
        break;
    case 1: // Options
        o.display_menu(window);
        break;
    case 2: // Quit
        gameOn = false;
        onWindow = false;
        break;
    }
}