#include <iostream>
#include <string>
#include <fstream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <cstring>
#include <typeinfo>
#include <tuple>
#include <map>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "common_build.h"

using namespace sf;


BuildClient::BuildClient(float x, float y, int team, int id, int hp): 
		is_selected(false), posX(x), posY(y), id(id), cont(0), frameBuild(1), hp(hp), hpMax(hp), team(team){
	lifeMax.setSize(Vector2f(70,3));
	lifeMax.setFillColor(sf::Color::Black);  
	int c = hp * 70 / hpMax;
	lifeRest.setSize(Vector2f(c,3));
	lifeRest.setFillColor(sf::Color::Green);
	lifeMax.setPosition(x, y - 8);
	lifeRest.setPosition(x, y - 8);		
}
	
void BuildClient::modifyHp(int new_hp){
	/*
		int life = hp * 70 / max_hp;
		lifeRest.setSize(Vector2f(life,3));
		int porcentual_life = hp * 100 / max_hp;
		if(porcentual_life < 30){
			lifeRest.setFillColor(sf::Color::Red);
			frameBuildClient = 0;
		} else {
			lifeRest.setFillColor(sf::Color::Green);
		}
		this->hp = new_hp;
		*/
}
	
bool BuildClient::is_there(float cord_x, float cord_y){
	int is_in = 0;
	if(this->posX <= cord_x && cord_x <= this->posX + this->largeBitsX) is_in += 1;
	if(this->posY <= cord_y && cord_y<= this->posY + this->largeBitsY) is_in += 1;
	return is_in == 2;
}

	
int BuildClient::get_team(){
	return team;
}
	
std::tuple<int, int, int, int> BuildClient::get_bits(){
	return std::make_tuple(posX, posY, largeBitsX, largeBitsY);
}
		
void BuildClient::selected_structure(){
    this->is_selected = true;
}

void BuildClient::deselected_structure(){
    this->is_selected = false;
}

int BuildClient::get_id_build(){
	return id;
}


void BuildClient::animateBuild(){}

void BuildClient::draw(RenderTarget &target, RenderStates states) const {}