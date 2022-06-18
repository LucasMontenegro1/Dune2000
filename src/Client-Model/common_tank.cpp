#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_tank.h"
#include "common_assault.h"

using namespace sf;

Tank::Tank(std::map <int, Vector2f> &frames, int cordX, int cordY, int id, int team, int hp): Unit(cordX, cordY, id, team, hp), frames(frames) {
    texture.loadFromFile("resources/units/harkonnenTank.png");
	sprite.setTexture(texture);
    sprite.setTextureRect(IntRect(5,2,30,25));
	sprite.setPosition(cordX, cordY);
    this->velocity = 0.1;	
	this->largeBitsX = 35;
	this->largeBitsY = 35;
	this->actualFrame = 17;
	this->actualFrameCanion = 49;
	canion.setTexture(texture);
	canion.setTextureRect(IntRect(8,109,10,18));
	canion.setPosition(cordX + 5, cordY + 1);
}

void Tank::draw(RenderTarget &target, RenderStates states) const {
	if(can_move) target.draw(selector);
	target.draw(sprite, states);
	target.draw(canion, states);
}

void Tank::modifyMovePosition(bool moveRight, bool moveLeft, 
							bool moveUp, bool moveDown){
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
	Vector2f &posicionFrame = frames[actualFrame];	
	sprite.setTextureRect(IntRect(posicionFrame.x, posicionFrame.y,30,25));

	actualFrameCanion = actualFrame + 32;
	Vector2f &posicionFrameCanion = frames[actualFrameCanion];
	canion.setTextureRect(IntRect(posicionFrameCanion.x, posicionFrameCanion.y,20,20));	
		
	canion.setPosition(posX + 5, posY + 1);
	cont++;
}


void Tank::updateCanion(){
	int frameDestiny = actualFrameCanion;
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
		if(moveUp) frameDestiny = 36;
		if(moveDown) frameDestiny = 46;
		else if(!moveUp && !moveDown) frameDestiny = 41;	
	}
	if(moveLeft){
		if(moveUp) frameDestiny = 61;
		if(moveDown) frameDestiny = 53;
		else if(!moveUp && !moveDown) frameDestiny = 57;		}
	if(!moveRight && !moveLeft && !moveUp && moveDown) frameDestiny = 49;
	if(!moveRight && !moveLeft && moveUp && !moveDown) frameDestiny = 33;
		
	if(actualFrameCanion > frameDestiny) actualFrameCanion--;
	if(actualFrameCanion < frameDestiny) actualFrameCanion++;
	if(actualFrameCanion == frameDestiny) weapon.animate(posX, posY, attacking);

	Vector2f &posicionFrameCanion = frames[actualFrameCanion];
	canion.setTextureRect(IntRect(posicionFrameCanion.x, posicionFrameCanion.y,20,20));
}


void Tank::animate_attack(){
	if(cont % 10 == 0) updateCanion();
	canion.setPosition(posX + 5,posY + 1);
	cont++;
}
