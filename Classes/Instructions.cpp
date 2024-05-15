#include "Instructions.h"

Instructions::Instructions() {
    selected = -1;
    music_flag = false;

    tex.loadFromFile("../Images/instructions.png");
    ins.setTexture(tex);

    if (!font.loadFromFile("../Fonts/virgo.ttf"))
        cout << "could not load" << endl;

    Ins[0].setFont(font);
    Ins[0].setFillColor(Color::Black);
    Ins[0].setString("BACK");
    Ins[0].setCharacterSize(30);
    Ins[0].setPosition(760, 440);


    //hoverbuffer.loadFromFile("sounds/effects/zap1.ogg");
    //hoversound.setBuffer(hoverbuffer);
    //hoversound.setVolume(100);

    //selectbuffer.loadFromFile("sounds/effects/zap2.ogg");
    //selectsound.setBuffer(selectbuffer);
    //selectsound.setVolume(100);
}

void Instructions::display_menu(RenderWindow& window)
{
    bool onWindow = true;
    while (onWindow && window.isOpen()) {
        Event s;
        Vector2i mousePos = Mouse::getPosition(window); // Get the position of the mouse relative to the window

        while (window.pollEvent(s))
        {
            if (s.type == Event::Closed) // If cross/close is clicked/pressed
                window.close();

            // Handling mouse movement
            if (Ins[0].getGlobalBounds().contains(mousePos.x, mousePos.y))
                Ins[0].setFillColor(Color::Red);
            else
                Ins[0].setFillColor(Color::Black);

            // Handling mouse clicks
            if (s.type == Event::MouseButtonReleased && s.mouseButton.button == Mouse::Left) {
                if (Ins[0].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    // selectsound.play();
                    onWindow = false;
                }
            }

            window.clear(Color::Black); // Clears the screen
            window.draw(ins);  // Draws the background
            window.draw(Ins[0]);  // Draw the BACK text

            window.display();
        }
    }
}


void Instructions::moveup() {
    if (selected - 1 >= 0) {
        Ins[selected].setFillColor(Color::Black); //the color turns back to white
        selected--;
        if (selected == -1)
            selected = 1;

        Ins[selected].setFillColor(Color::Red);


    }
}

void Instructions::movedown() {
    if (selected + 1 < size) {
        Ins[selected].setFillColor(Color::Black); //the color turns back to white
        selected++;
        if (selected == size)
            selected = 0;

        Ins[selected].setFillColor(Color::Red);


    }
}

int Instructions::getSelected() {
    return selected;
}