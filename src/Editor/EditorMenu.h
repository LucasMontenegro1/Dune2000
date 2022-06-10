//
// Created by lucas on 09/06/22.
//

#ifndef EDITOR_EDITORMENU_H
#define EDITOR_EDITORMENU_H

#include "Button.h"

class EditorMenu {
    sf::Texture menuTexture;
    sf::RectangleShape canvas;
    Button sand;
    Button cliff;
    Button rocks;
public:
    EditorMenu(float x, float y, float height, float width);
    void render(sf::RenderWindow& target);
};


#endif //EDITOR_EDITORMENU_H
