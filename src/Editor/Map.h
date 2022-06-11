//
// Created by lucas on 10/06/22.
//

#ifndef EDITOR_MAP_H
#define EDITOR_MAP_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "ground.h"

#define size 16;

class Map {
    sf::Texture sand;
    std::vector<std::vector<sf::Sprite>> Terrains;
    int x;
    int y;
public:
    Map(int x, int y);

    void render(sf::RenderWindow& window);
    void update(sf::RenderWindow& window,sf::Event& e);
};


#endif //EDITOR_MAP_H
