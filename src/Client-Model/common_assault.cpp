#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_assault.h"

using namespace sf;

Assault::Assault(){
	image.loadFromFile("resources/assaultWeapon/002b06a9.bmp");
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

void Assault::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}

void Assault::updateTexture(){

}

void Assault::animate(float posX, float posY, bool is_attacking){
	if(is_attacking){
		sprite.setPosition(posX, posY);
		if(cont % 10 == 0) updateTexture();
		cont++;
	}
}