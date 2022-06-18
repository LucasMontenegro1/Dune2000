#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_assault.h"

#include <iostream>



Unit::Unit(int cordX, int cordY, int id, int team, int hp): posX(cordX), posY(cordY), 
	can_move(false), destX(cordX), destY(cordY), id(id), selector{}, team(team), cont(0), 
	hp(hp), max_hp(hp), attacking(false) {
		lifeMax.setSize(Vector2f(30,3));
		lifeMax.setFillColor(sf::Color::Black);
	}


void Unit::draw(RenderTarget &target, RenderStates states) const {
	if(hp < max_hp){
		target.draw(lifeMax, states);
		target.draw(lifeRest, states);
	}
	if(can_move) target.draw(selector);
	target.draw(sprite, states);
}


bool Unit::is_there(float cord_x, float cord_y){
	int is_in = 0;
	if(this->posX <= cord_x && cord_x <= this->posX + this->largeBitsX) is_in += 1;
	if(this->posY <= cord_y && cord_y<= this->posY + this->largeBitsY) is_in += 1;
	return is_in == 2;
}

Assault Unit::get_weapon(){
	Assault a;
	return a;
}

void Unit::setMove(float x, float y){
	this->destX = x;
	this->destY = y;
}

void Unit::setAttack(std::tuple<float, float> position_target){
	this->attackX = std::get<0>(position_target);
	this->attackY = std::get<1>(position_target);
	this->attacking = true;
}

bool Unit::is_attacking(){
	return attacking;
}

void Unit::enable_move(){
	this->can_move = true;
	selector.enable_selection(posX, posY);
}

int Unit::get_id_unit(){
	return this->id;
}

int Unit::get_hp(){
	return hp;
}

void Unit::modifyHp(int new_hp){
	int life = hp * 30 / max_hp;
	lifeRest.setSize(Vector2f(life,3));
	lifeRest.setFillColor(sf::Color::Green);
	this->hp = new_hp;
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

int Unit::get_team(){
	return team;
}

void Unit::move(){
	float moveX = posX;
	float moveY = posY;
	bool moveRight = false; bool moveLeft = false; 
	bool moveUp = false; bool moveDown = false;
	if(destX > posX){
		moveX +=  velocity;
		moveRight = true;
		attacking = false;
	}
	if(destX < posX){
		moveX -=  velocity;
		moveLeft = true;
		attacking = false;
	}
	if(destY > posY){
		moveY +=  velocity;
		moveDown = true;
		attacking = false;
	}
	if(destY < posY){
		moveY -=  velocity;
		moveUp = true;
		attacking = false;
	}
	modifyMovePosition(moveRight, moveLeft, moveUp, moveDown);
	sprite.setPosition(moveX, moveY);
	selector.enable_selection(moveX, moveY);
	lifeMax.setPosition(moveX, moveY - 5);
	lifeRest.setPosition(moveX, moveY - 5);
	this->posX = moveX;
	this->posY = moveY;
	if((int) moveX == (int) destX) this->destX = moveX;
	if((int) moveY == (int) destY) this->destY = moveY;		
}

std::tuple<float, float> Unit::get_position(){
	return std::make_tuple(this->posX, this->posY);
}

Unit& Unit::operator=(const Unit&& other) {
	this->posX = other.posX;
	this->posY = other.posY;
	this->can_move = other.can_move;
	this->destX = other.destX;
	this->destY = other.destY;
	this->id = other.id;
	this->velocity = other.velocity;
	this->largeBitsX = other.largeBitsX;
	this->largeBitsY = other.largeBitsY;
	this->actualFrame = other.actualFrame;
	this->sprite = other.sprite;
	this->texture = other.texture;
	this->selector = other.selector;
	this->team = other.team;
	this->cont = other.cont;
    return *this;
}