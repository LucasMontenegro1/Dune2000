#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"

//Este constructor esta para el caso de crear una unidad temporal para get_unit
Unit::Unit() {}


Unit unit(int cordX, int cordY): posX(cordX), posY(cordY), can_move(false) {}


void Unit::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}


void Unit::enable_move(){
	this->can_move = true;
}


void Unit::no_enable_move(){
	this->can_move = false;
}


bool Unit::can_moves(){
	return this->can_move;
}


Unit& Unit::operator=(const Unit&& other) {
    this->sprite = other.sprite;
	this->texture = other.texture;
	this->can_move = other.can_move;
	this->posX = other.posX;
	this->posY = other.posY;
    return *this;
}

