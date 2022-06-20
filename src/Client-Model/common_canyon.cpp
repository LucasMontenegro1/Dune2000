#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "common_canyon.h"


using namespace sf;

Canyon::Canyon(){
	image.loadFromFile("resources/canyonWeapon/49.bmp");
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	cont = 0;
	buffer.loadFromFile("resources/sounds/attacks/shot.wav");
	attackSound.setBuffer(buffer);
	attackSound.setVolume(2);
}

void Canyon::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}

void Canyon::updateTexture(int frame){
	std::string f = "resources/canyonWeapon/" + std::to_string(frame) + ".bmp";
	image.loadFromFile(f);
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}

void Canyon::animate(float posX, float posY, bool is_attacking, int frame){
	updateTexture(frame);
	if(is_attacking){
		if(cont % 500 == 0 || cont + 1 % 500 == 0 || cont + 1 % 500 == 0){
			attackSound.play();
			sprite.setPosition(posX, posY);
		} else {
			sprite.setPosition(-50,-50);
		}
		cont++;
	}
}

Sprite Canyon::getSprite(){
    return sprite;
}