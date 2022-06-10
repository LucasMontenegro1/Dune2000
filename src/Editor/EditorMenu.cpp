//
// Created by lucas on 09/06/22.
//

#include "EditorMenu.h"

EditorMenu::EditorMenu(float x, float y, float width, float height) {
    menuTexture.loadFromFile("../resources/menuCanvas.png");
    this->canvas.setPosition(sf::Vector2f(x,y));
    this->canvas.setSize(sf::Vector2f(width,height));
    this->canvas.setTexture(&menuTexture);
}

void EditorMenu::render(sf::RenderWindow &target) {
    target.draw(this->canvas);
}
