#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_canyon.h"


using namespace sf;

Canyon::Canyon(){
	image.loadFromFile("resources/assaultWeapon/002b06a9.bmp");
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	cont = 0;
}

void Canyon::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}

void Canyon::updateTexture(){
	
}

void Canyon::animate(float posX, float posY, bool is_attacking){
	if(is_attacking){
		if(cont % 6 == 0 || cont + 1 % 6 == 0 || cont + 1 % 6 == 0){
			sprite.setPosition(posX, posY);
		} else {
			sprite.setPosition(-50,-50);
		}
		updateTexture();
		cont++;
	}
}

Sprite Canyon::getSprite(){
    return sprite;
}