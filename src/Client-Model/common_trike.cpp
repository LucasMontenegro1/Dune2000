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
	this->velocity = 0.1;
	this->largeBitsX = 30;
	this->largeBitsY = 30;
	this->actualFrame = 17;
}


void Trike::modifyMovePosition(bool moveRight, bool moveLeft, bool moveUp, bool moveDown){
	int frameDestiny;
	if(moveRight){
		if(moveUp) frameDestiny = 5;
		if(moveDown) frameDestiny = 13;
		else if(!moveUp && !moveDown) frameDestiny = 9;		
	}
	if(moveLeft){
		if(moveUp) frameDestiny = 29;
		if(moveDown) frameDestiny = 21;
		else if(!moveUp && !moveDown) frameDestiny = 25;
	}
	if(!moveRight && !moveLeft && !moveUp && moveDown) frameDestiny = 17;
	if(!moveRight && !moveLeft && moveUp && !moveDown) frameDestiny = 1;

	if(cont % 10 == 0){
		if(actualFrame > frameDestiny) actualFrame--;
		if(actualFrame < frameDestiny) actualFrame++;
	}
	cont++;
	Vector2f &posicionFrame = frames[actualFrame];	
	sprite.setTextureRect(IntRect(posicionFrame.x, posicionFrame.y,30,25));
	}
	
void Trike::animate_attack(){
	if(cont % 30 == 0) pointTo();
	sprite.setPosition(posX,posY);
	cont++;
}

Assault Trike::get_weapon(){
	return weapon;
}

void Trike::pointTo(){
	int frameDestiny = actualFrame;
	bool moveRight = false; bool moveLeft = false; 
	bool moveUp = false; bool moveDown = false;
	if(attackX > posX && attackX - 15 > posX){
		moveRight = true;
	}
	if(attackX < posX && attackX + 15 < posX){
		moveLeft = true;
	}
	if(attackY > posY && attackY - 15 > posY){
		moveDown = true;
	}
	if(attackY < posY && attackY + 15 < posY){
		moveUp = true;
	}
	if(moveRight){
		if(moveUp) frameDestiny = 5;
		if(moveDown) frameDestiny = 13;
		else if(!moveUp && !moveDown) frameDestiny = 9;	
	}
	if(moveLeft){
		if(moveUp) frameDestiny = 29;
		if(moveDown) frameDestiny = 21;
		else if(!moveUp && !moveDown) frameDestiny = 25;
	}

	if(!moveRight && !moveLeft && !moveUp && moveDown) frameDestiny = 17;
	if(!moveRight && !moveLeft && moveUp && !moveDown) frameDestiny = 1;
		
	if(actualFrame > frameDestiny) actualFrame--;
	if(actualFrame < frameDestiny) actualFrame++;
	if(actualFrame == frameDestiny) weapon.animate(posX + 5, posY + 5, attacking);

	Vector2f &posicionFrame = frames[actualFrame];
	sprite.setTextureRect(IntRect(posicionFrame.x, posicionFrame.y,30,25));
}

Trike::~Trike(){}

