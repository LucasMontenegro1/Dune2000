//
// Created by lucas on 10/06/22.
//

#ifndef EDITOR_EDITOR_H
#define EDITOR_EDITOR_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Editor {
private:
    RenderWindow window;
    bool game_over;

public:
    Editor();
    void gameloop();
};


#endif //EDITOR_EDITOR_H
