#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_trike.h"

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
	

Trike::~Trike(){}

