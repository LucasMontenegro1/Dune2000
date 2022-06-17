//
// Created by lucas on 10/06/22.
//

#ifndef EDITOR_EDITOR_H
#define EDITOR_EDITOR_H
#include <SFML/Graphics.hpp>
#include "EditorMenu.h"
#include "camera.h"
#include "ConstructionCenter.h"

using namespace sf;

class Editor {
private:
    std::vector<ConstructionCenter*> centers;
    std::string name;
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
    int players;
    void updateCamera();
    bool ceckConstruction(int, int);
    void setSprite(int);

public:
    Editor(sf::Vector2i resolution,std::string& name,int x, int y, int players);
    void gameloop();
    ~Editor();
    void setMap(std::vector<std::vector<int>>);
    void setCenters(std::vector<ConstructionCenter *>& centers);
};


#endif //EDITOR_EDITOR_H
