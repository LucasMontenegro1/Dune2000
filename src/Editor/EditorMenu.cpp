//
// Created by lucas on 09/06/22.
//

#include "EditorMenu.h"

#define BTN_WIDTH 160
#define BTN_HEIGTH 90
#define INITIAL_X 30
#define INITIAL_Y 520
#define DIFERENCE 229
#define DIFERENCE_Y 100


EditorMenu::EditorMenu(float x, float y, float width, float height) {
    menuTexture.loadFromFile("../resources/menuCanvas.png");
    this->canvas.setPosition(sf::Vector2f(x,y));
    this->canvas.setSize(sf::Vector2f(width,height));
    this->canvas.setTexture(&menuTexture);

    sf::Texture texture;
    texture.loadFromFile("../resources/sand.bmp");
    this->sand.setTexture(texture);
    this->sand.setPosition(INITIAL_X,INITIAL_Y);
    this->sand.setSize(BTN_WIDTH,BTN_HEIGTH);

    texture.loadFromFile("../resources/rocks.bmp");
    this->rocks.setTexture(texture);
    this->rocks.setPosition(INITIAL_X+ DIFERENCE, INITIAL_Y);
    this->rocks.setSize(BTN_WIDTH, BTN_HEIGTH);

    texture.loadFromFile("../resources/spice.bmp");
    this->spice.setTexture(texture);
    this->spice.setPosition(INITIAL_X+ DIFERENCE*2, INITIAL_Y);
    this->spice.setSize(BTN_WIDTH, BTN_HEIGTH);

}

void EditorMenu::render(sf::RenderWindow &target) {
    target.draw(this->canvas);
    sand.render(target);
    rocks.render(target);
    spice.render(target);
}

void EditorMenu::update(sf::RenderWindow &target, sf::Event &e) {
    this->sand.update(e,target);
    this->rocks.update(e, target);
    this->spice.update(e, target);
}
