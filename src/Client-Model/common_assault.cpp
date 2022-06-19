#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "common_assault.h"


using namespace sf;

Assault::Assault(){
	image.loadFromFile("resources/assaultWeapon/1.bmp");
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	cont = 0;
	buffer.loadFromFile("resources/sounds/attacks/shot.wav");
	attackSound.setBuffer(buffer);
	attackSound.setVolume(2);
}

void Assault::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}

void Assault::updateTexture(int frame){
	std::string f = "resources/assaultWeapon/" + std::to_string(frame) + ".bmp";
	image.loadFromFile(f);
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}


void Assault::animate(float posX, float posY, bool is_attacking, int frame){
	if(is_attacking){
		updateTexture(frame);
		if(cont % 8 == 0 || cont + 1 % 8 == 0 || cont - 1 % 8 == 0){
			attackSound.play();
			sprite.setPosition(posX, posY);
		} else {
			sprite.setPosition(-50,-50);
		}
		cont++;
	}
}

Sprite Assault::getSprite(){
    return sprite;
}