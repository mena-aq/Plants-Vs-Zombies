#include "InputName.h"

InputName::InputName() {
    music_flag = false;
    tex.loadFromFile("../Images/login_screen.jpg");
    ins.setTexture(tex);
    srand(time(0));//gameover_theme
    //music.loadFromFile("sounds/zap1.ogg");
    //MUSICA.setBuffer(music);

    if (!font.loadFromFile("../Fonts/virgo.ttf"))
        cout << "could not load" << endl;

    txt[0].setFont(font);
    txt[0].setFillColor(Color::Black);
    txt[0].setString("START");
    txt[0].setCharacterSize(30);
    txt[0].setPosition(420, 480);

    selected = -1;
}

string InputName::display_menu(RenderWindow& window)
{
    selected = -1;
    Event s;
    Text playerText;
    string playerInput;
    playerText.setFont(font);
    playerText.setCharacterSize(30);
    playerText.setFillColor(sf::Color::White);
    //playerText.setPosition(390, 280);
    playerText.setPosition(232, 294);

    bool onWindow = true;
    while (onWindow && window.isOpen())
    {
        Vector2i mousePos = Mouse::getPosition(window); 

        while (window.pollEvent(s))
        {
            if (s.type == Event::Closed) 
                window.close();

            if (s.type == Event::TextEntered)
            {
                if (s.text.unicode == '\b' && !playerInput.empty()) // handle backspace
                {
                    playerInput.pop_back();
                }
                else if (s.text.unicode < 128 && s.text.unicode != '\b' && playerInput.size() < 20) // handle normal character input
                {
                    playerInput += static_cast<char>(s.text.unicode);
                }
                playerText.setString(playerInput);
            }

            if (txt[0].getGlobalBounds().contains(mousePos.x, mousePos.y))
                txt[0].setFillColor(Color::Red);
            else
                txt[0].setFillColor(Color::Black);

            if (s.type == Event::MouseButtonReleased && s.mouseButton.button == Mouse::Left) {
                if (txt[0].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // selectsound.play();
                     // Trigger the action here, e.g., starting the game
                     //music.stop();
                     //Game G;
                    onWindow = false;
                    //G.start_game(playerInput, n);
                    //return;
                }
            }
        }

        window.clear(Color::Black); // Clears the screen
        window.draw(ins);  // Draws the background
        window.draw(txt[0]);
        window.draw(playerText);

        window.display();
    }
    return playerInput;
}


void InputName::moveup() {
    if (selected - 1 >= 0) {
        txt[selected].setFillColor(Color::Black); //the color turns back to white
        selected--;
        if (selected == -1)
            selected = 1;

        txt[selected].setFillColor(Color::Red);


    }
}

void InputName::movedown() {
    if (selected + 1 < size) {
        txt[selected].setFillColor(Color::Black); //the color turns back to white
        selected++;
        if (selected == size)
            selected = 0;

        txt[selected].setFillColor(Color::Red);


    }
}

int InputName::getSelected() {
    return selected;
}