//
// Created by lucas on 10/06/22.
//

#include "Map.h"

Map::Map(int x, int y): Terrains(y,std::vector<sf::Sprite>(x)) {
    this->sand.loadFromFile("../resources/terrain.bmp");
    this->x = y;
    this->y = x;
    for (int i = 0; i < this->x; ++i) {
        for (int j = 0; j < this->y; ++j) {
            this->Terrains[i][j].setTexture(sand);
            this->Terrains[i][j].setTextureRect(IntRect(0,8,16,16));
        }
    }
}

void Map::render(sf::RenderWindow& window) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y ; ++j) {
            Terrains[i][j].setPosition(16*i,16*j);
            window.draw(Terrains[i][j]);
        }
    }
}

void Map::update(sf::RenderWindow& window, sf::Event &e) {
    sf::Vector2i WinPos = sf::Mouse::getPosition(window);
    if (WinPos.x < 1366*0.75) {
        sf::Vector2f mousePosition = window.mapPixelToCoords(WinPos);
        if (e.type == e.MouseButtonReleased) {
            if (Terrains[mousePosition.x / 16][mousePosition.y / 16].getGlobalBounds().contains(mousePosition)) {
                Terrains[mousePosition.x / 16][mousePosition.y / 16].setTextureRect(IntRect(112, 240, 16, 16));
                std::cout << "dcdsf";
            }
        }
    }
}


