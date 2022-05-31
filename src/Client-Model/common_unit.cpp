#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"

//Este constructor esta para el caso de crear una unidad temporal para get_unit, aunque
//no estoy seguro si hara falta
Unit::Unit() {}


Unit::Unit(int cordX, int cordY, int id): posX(cordX), posY(cordY), 
	can_move(false), destX(cordX), destY(cordY), id(id) {}


void Unit::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}


bool Unit::is_there(float cord_x, float cord_y){
	int is_in = 0;
	if(this->posX <= cord_x && cord_x <= this->posX + this->largeBitsX) is_in += 1;
	if(this->posY <= cord_y && cord_y<= this->posY + this->largeBitsY) is_in += 1;
	return is_in == 2;
}


void Unit::setLastMove(float x, float y){
	this->posX = x;
	this->posY = y;
	this->can_move = false;
	sprite.setPosition(x,y);
}

void Unit::enable_move(){
	this->can_move = true;
}

int Unit::get_id_unit(){
	return this->id;
}


void Unit::no_enable_move(){
	this->can_move = false;
}


bool Unit::can_moves(){
	return this->can_move;
}

std::tuple<int, int, int, int> Unit::get_bits(){
	return std::make_tuple(posX, posY, largeBitsX, largeBitsY);
}

bool Unit::is_in_destiny(){
	return destX == posX && destY == posY;
}

Unit& Unit::operator=(const Unit&& other) {
    this->sprite = other.sprite;
	this->texture = other.texture;
	this->can_move = other.can_move;
	this->posX = other.posX;
	this->posY = other.posY;
    return *this;
}


