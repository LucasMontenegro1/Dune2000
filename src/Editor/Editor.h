//
// Created by lucas on 10/06/22.
//

#ifndef EDITOR_EDITOR_H
#define EDITOR_EDITOR_H
#include <SFML/Graphics.hpp>
#include "EditorMenu.h"
#include "camera.h"

using namespace sf;

class Editor {
private:
    int posX;
    int posY;
    View view;
    View menu_view;
    RenderWindow window;
    EditorMenu menu;
    Camera* camera;
    Ground* ground;
    std::vector<std::vector<int>> level;
    bool game_over;
    void updateCamera();

public:
    Editor(sf::Vector2i resolution);
    void gameloop();
};


#endif //EDITOR_EDITOR_H
