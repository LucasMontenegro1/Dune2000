//
// Created by lucas on 18/06/22.
//

#ifndef CLIENT_UNITBUTTON_H
#define CLIENT_UNITBUTTON_H
#include "Button.h"

class UnitButton: public Button{
private:
    sf::Font font;
    sf::Text timerText;
    sf::Text timesPressedText;
    int timesPressed;
public:
    UnitButton();
};


#endif //CLIENT_UNITBUTTON_H
