#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_infantery.h"


Trike::Trike(int cordX, int cordY, int id): Unit(cordX, cordY, id) {
	texture.loadFromFile("trike.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(5,60,30,30));
	sprite.setPosition(x, y);
	this->velocity = 0.16
	this->largeBitsX = 30;
	this->largeBitsY = 30;
	
}


void Trike::modifyMovePosition(bool moveRight, bool moveLeft, bool moveUp, bool moveDown){
	if(moveRight){
		if(moveUp) sprite.setTextureRect(IntRect(140,5,30,25));
		if(moveDown) sprite.setTextureRect(IntRect(140,35,30,25));
		else if(!moveUp && !moveDown) sprite.setTextureRect(IntRect(5,35,30,25));		
	}
	if(moveLeft){
		if(moveUp) sprite.setTextureRect(IntRect(140,85,30,25));
		if(moveDown) sprite.setTextureRect(IntRect(140,60,30,30));	
		else if(!moveUp && !moveDown) sprite.setTextureRect(IntRect(5,85,30,25));			
	}
	if(!moveRight && !moveLeft && !moveUp && moveDown){
		sprite.setTextureRect(IntRect(5,60,30,30));			
	}
	if(!moveRight && !moveLeft && moveUp && !moveDown){
		sprite.setTextureRect(IntRect(5,5,30,30));
	}
}


void Trike::move(){
	float moveX = posX;
	float moveY = posY;
	bool moveRight = false; bool moveLeft = false; 
	bool moveUp = false; bool moveDown = false;
	if(destX > x){
		moveX +=  velocity;
		moveRight = true;
	}
	if(destX < x){
		moveX -=  velocity;
		moveLeft = true;
	}
	if(destY > y){
		moveY +=  velocity;
		moveDown = true;
	}
	if(destY < y){
		moveY -=  velocity;
		moveUp = true;
	}
	modifyMovePosition(moveRight, moveLeft, moveUp, moveDown);
	sprite.setPosition(moveX, moveY);
	this->posX = moveX;
	this->posY = moveY;
	if((int) moveX == (int) goX) this->destX = moveX;
	if((int) moveY == (int) goY) this->destY = moveY;		
	}
}




