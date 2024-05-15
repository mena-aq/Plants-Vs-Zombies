#include "Options.h"

Options::Options() {
    menu_tx.loadFromFile("../Images/options.jpg");
    menu.setTexture(menu_tx);
    menu.setScale(1.0, 0.55);

    musicFlag = true;
    selected = -1; // Default selection

    if (!font.loadFromFile("../Fonts/virgo.ttf")) {
        cout << "could not load font" << endl;
    }

    // Initialize options menu texts
    options_menu[0].setFont(font);
    options_menu[0].setFillColor(Color::Black);
    options_menu[0].setString("Music : ON");
    options_menu[0].setCharacterSize(30);
    options_menu[0].setPosition(600, 250);  // Directly set x and y

    options_menu[1].setFont(font);
    options_menu[1].setFillColor(Color::Black);
    options_menu[1].setString("BACK");
    options_menu[1].setCharacterSize(30);
    options_menu[1].setPosition(600, 310);  // Directly set x and y

    // Load sound effects
    //hoverbuffer.loadFromFile("sounds/effects/zap1.ogg");
    //hoversound.setBuffer(hoverbuffer);
    //hoversound.setVolume(100);

    //selectbuffer.loadFromFile("sounds/effects/zap2.ogg");
    //selectsound.setBuffer(selectbuffer);
    //selectsound.setVolume(100);
}

void Options::display_menu(RenderWindow& window) {
    bool onWindow = true;
    while (onWindow && window.isOpen()) {
        Event s;
        while (window.pollEvent(s)) {
            if (s.type == Event::Closed)
                window.close();

            int mouseX = Mouse::getPosition(window).x;  // Get mouse x-coordinate
            int mouseY = Mouse::getPosition(window).y;  // Get mouse y-coordinate

            // Handle mouse movement and clicks
            for (int i = 0; i < size; i++) {
                if (options_menu[i].getGlobalBounds().contains(mouseX, mouseY))
                    options_menu[i].setFillColor(Color::Red);
                else
                    options_menu[i].setFillColor(Color::Black);
            }

            if (s.type == Event::MouseButtonReleased && s.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < size; i++) {
                    if (options_menu[i].getGlobalBounds().contains(mouseX, mouseY)) {
                        //selectsound.play();
                        executeOption(i, window, onWindow);
                        break;
                    }
                }
            }
        }

        window.clear(Color::Black);
        window.draw(menu);
        for (int i = 0; i < size; i++) {
            window.draw(options_menu[i]);
        }
        window.display();
    }
}

void Options::executeOption(int index, RenderWindow& window, bool& onWindow) {
    while (onWindow && window.isOpen()) {
        switch (index) {
        case 0: // Toggle Music
            musicFlag = !musicFlag;
            options_menu[0].setString(musicFlag ? "Music : ON" : "Music : OFF");
            break;
        case 1: // Back
            //window.close();
            onWindow = false;
            break;
        }
    }
}