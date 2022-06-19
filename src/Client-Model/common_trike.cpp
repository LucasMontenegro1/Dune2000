#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_trike.h"
#include "common_assault.h"
#include <iostream>


using namespace sf;

Trike::Trike(std::map <int, Vector2f> &frames, int cordX, int cordY, int id, int team, int hp): Unit(cordX, cordY, id, team, hp), frames(frames) {
	texture.loadFromFile("resources/units/trike.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(5,60,30,30));
	sprite.setPosition(cordX, cordY);
	this->velocity = 0.35;
	this->largeBitsX = 35;
	this->largeBitsY = 35;
	this->actualFrame = 17;
}


void Trike::modifyMovePosition(bool moveRight, bool moveLeft, bool moveUp, bool moveDown){
	int frameDestiny = Unit::calculeFramePosition(moveRight, moveLeft, moveUp, moveDown);
	if(actualFrame > frameDestiny) actualFrame--;
	if(actualFrame < frameDestiny) actualFrame++;
	Vector2f &posicionFrame = frames[actualFrame];	
	sprite.setTextureRect(IntRect(posicionFrame.x, posicionFrame.y,30,25));
	}
	
void Trike::animate_attack(){
	pointTo();
	sprite.setPosition(posX,posY);
}


void Trike::pointTo(){
	int frameDestiny = actualFrame;
	bool moveRight = false; bool moveLeft = false; 
	bool moveUp = false; bool moveDown = false;
	if(attackX > posX && attackX - 15 > posX) moveRight = true;
	if(attackX < posX && attackX + 15 < posX) moveLeft = true;
	if(attackY > posY && attackY - 15 > posY) moveDown = true;
	if(attackY < posY && attackY + 15 < posY) moveUp = true;
	frameDestiny = Unit::calculeFramePosition(moveRight, moveLeft, moveUp, moveDown);

	if(actualFrame > frameDestiny) actualFrame--;
	if(actualFrame < frameDestiny) actualFrame++;
	if(actualFrame == frameDestiny) weapon.animate(posX + 5, posY + 5, attacking, actualFrame);

	Vector2f &posicionFrame = frames[actualFrame];
	sprite.setTextureRect(IntRect(posicionFrame.x, posicionFrame.y,30,25));
}

Sprite Trike::get_weapon(){
	return weapon.getSprite();
}

Trike::~Trike(){}

