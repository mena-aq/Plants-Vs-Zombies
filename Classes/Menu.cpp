#include "Menu.h"

Menu::Menu(Player* player) :player(player), levels(player)
{
    menu_tx.loadFromFile("../Images/mainMenu.png");
    menu.setTexture(menu_tx);

    // Change this to an OGG file format
    music.openFromFile("../Music/main_song.ogg");
    music.setVolume(20);
    music.setLoop(true);
    music_pause = false;

    //hoverbuffer.loadFromFile("../Music/zap1.ogg");
    //hoversound.setBuffer(hoverbuffer);
    //hoversound.setVolume(40);

    //selectbuffer.loadFromFile("../Music/zap2.ogg");  
    //selectsound.setBuffer(selectbuffer);
    //selectsound.setVolume(40);

    selected = -1;//default

    if (!font.loadFromFile("../Fonts/virgo.ttf"))
        cout << "could not load" << endl;

    main_menu[0].setFont(font);
    main_menu[0].setFillColor(Color::Black);
    main_menu[0].setString("PLAY");
    main_menu[0].setCharacterSize(36);
    main_menu[0].setPosition(432, 180);

    main_menu[1].setFont(font);
    main_menu[1].setFillColor(Color::Black);
    main_menu[1].setString("LEADERBOARD");
    main_menu[1].setCharacterSize(36);
    main_menu[1].setPosition(368, 230);

    main_menu[2].setFont(font);
    main_menu[2].setFillColor(Color::Black);
    main_menu[2].setString("OPTIONS");
    main_menu[2].setCharacterSize(36);
    main_menu[2].setPosition(408, 280);

    main_menu[3].setFont(font);
    main_menu[3].setFillColor(Color::Black);
    main_menu[3].setString("INSTRUCTIONS");
    main_menu[3].setCharacterSize(36);
    main_menu[3].setPosition(372, 330);

    main_menu[4].setFont(font);
    main_menu[4].setFillColor(Color::Black);
    main_menu[4].setString("EXIT");
    main_menu[4].setCharacterSize(36);
    main_menu[4].setPosition(448, 380);

    score.setFont(font);
    score.setCharacterSize(32);
    score.setFillColor(sf::Color::White);
    score.setPosition(760, 480);

    music.play();
    musicIS = true;
}

void Menu::display_menu(RenderWindow& window)
{
    bool onWindow = true;
    while (onWindow && window.isOpen()) {
        Event s;
        Vector2i mousePos = Mouse::getPosition(window);
        while (window.pollEvent(s))
        {
            if (s.type == Event::Closed)
                window.close();
            for (int i = 0; i < 5; i++) {
                if (main_menu[i].getGlobalBounds().contains(mousePos.x, mousePos.y))
                    main_menu[i].setFillColor(Color::Red);
                else
                    main_menu[i].setFillColor(Color::Black);
            }

            // Handling mouse clicks
            if (s.type == Event::MouseButtonReleased && s.mouseButton.button == Mouse::Left) {
                for (int i = 0; i < 5; i++) {
                    if (main_menu[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        //selectsound.play();
                        executeAction(i, window,onWindow);
                        break;
                    }
                }
            }
        }

        std::ostringstream oss2;
        oss2 << "Score: " << player->getScore();
        this->score.setString(oss2.str());
        window.clear();
        window.draw(menu);
        for (int i = 0; i < 5; i++)
            window.draw(main_menu[i]);
        window.draw(score);
        window.display();
    }
}

void Menu::executeAction(int index, RenderWindow& window,bool& onWindow) {
    switch (index) {
    case 0:
        levels.display_menu(window);
        break;
    case 1:
        HS.display_menu(window);
        break;
    case 2:
        optionMenu.display_menu(window);
        break;
    case 3:
        InstructionsMenu.display_menu(window);
        break;
    case 4:
        onWindow = false;
        break;
    default:
        break;
    }
    cout << "function end";
}
void Menu::moveup() {
    if (selected - 1 >= 0) {
        main_menu[selected].setFillColor(Color::White); //the color turns back to white
        selected--;
        if (selected == -1)
            selected = 2;

        main_menu[selected].setFillColor(Color::Red);


    }
}

void Menu::movedown() {
    if (selected + 1 < 5) {
        main_menu[selected].setFillColor(Color::White); //the color turns back to white
        selected++;
        if (selected == 5)
            selected = 0;

        main_menu[selected].setFillColor(Color::Red);


    }
}
int Menu::getSelected() {
    return selected;
}