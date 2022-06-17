//
// Created by lucas on 13/06/22.
//

#include "ConstructionCenter.h"
#include "Constants.h"

ConstructionCenter::ConstructionCenter(int x, int y): x(x), y(y), selected(false) {
    texture.loadFromFile("../resources/constructionCenter.png");
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(TSIZE*3,TSIZE*3));
    shape.setPosition(x*TSIZE,y*TSIZE);
}

void ConstructionCenter::render(sf::RenderWindow&target) {
    target.draw(shape);
}

sf::Vector2i ConstructionCenter::getPosition() const {
    return {x,y};
}

ConstructionCenter::ConstructionCenter() {
    texture.loadFromFile("../resources/constructionCenter.png");
    shape.setTexture(&texture);
    shape.setSize(sf::Vector2f(TSIZE*3,TSIZE*3));
}

void ConstructionCenter::setPosition(int x , int y ) {
    this->x = x;
    this->y = y;
    shape.setPosition(x*TSIZE,y*TSIZE);
}

void ConstructionCenter::select() {
    texture.loadFromFile("../resources/constructionCenterS.png");
    shape.setTexture(&texture);
    selected = true;
}

void ConstructionCenter::unSelect() {
    texture.loadFromFile("../resources/constructionCenter.png");
    shape.setTexture(&texture);
    selected = false;
}

bool ConstructionCenter::isSelected() {
    return selected;
}


