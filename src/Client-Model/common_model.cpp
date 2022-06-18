#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_ground.h"
#include "common_model.h"
#include <iostream>


Model::Model(std::map <int, Unit*> &units, Ground &grounds, int team): 
		units(units), ground(grounds), one_unit_can_moves(false), team(team) {}
		
/*	
void Model::update(std::map <int, Unit*> &new_units){
	for(auto iter = new_units.begin(); iter != new_units.end(); ++iter){
		std::tuple<float, float> destiny = iter->second->get_position();
		this->units[iter->first]->setMove(std::get<0>(destiny), std::get<1>(destiny));
		delete iter->second;
	}	
}
*/

int Model::get_team(){
	return team;
}

int Model::get_y_size(){
	return ground.get_ground_y_size();
}

int Model::get_x_size(){
	return ground.get_ground_x_size();
}

int Model::get_unit(float cordX, float cordY){
	int id;
	for(auto iter = units.begin(); iter != units.end(); ++iter){
		if(iter->second->is_there(cordX, cordY)) id = iter->second->get_id_unit();
	}	
	return id;
}


std::vector<int> Model::get_units_can_moves(){
	std::vector<int> ids;
	for(auto iter = units.begin(); iter != units.end(); ++iter){
		if(iter->second->can_moves()) ids.push_back(iter->first);
	}	
	return ids;	
}

void Model::no_enable_moves(){
	if(a_unit_can_moves()){
		for(auto iter = units.begin(); iter != units.end(); ++iter){
			iter->second->no_enable_move();
		}	

	}
	this->one_unit_can_moves = false;
}


bool Model::a_unit_can_moves(){
	return this->one_unit_can_moves;
}


void Model::unit_enable_move(int unit_id){
	/*
	if(units[unit_id]->get_team() == team){
		units[unit_id]->enable_move();
		this->one_unit_can_moves = true;
	}
	*/
	units[unit_id]->enable_move();
	this->one_unit_can_moves = true;
}


bool Model::is_unit_there(float cordX, float cordY){
	bool is_here = false;
	for(auto iter = units.begin(); iter != units.end(); ++iter){
		if(iter->second->is_there(cordX, cordY) && iter->second->get_team() == team) is_here = true;
	}	
	return is_here;
}

bool Model::is_enemy_there(float cordX, float cordY){
	bool is_here = false;
	for(auto iter = units.begin(); iter != units.end(); ++iter){
		if(iter->second->is_there(cordX, cordY) && iter->second->get_team() != team) is_here = true;
	}	
	return is_here;
}

void Model::move_by_position(int id){
	if(!units[id]->is_in_destiny()) units[id]->move();
}



int Model::get_units_size(){
	return this->units.size();
}


Ground &Model::get_grounds(){
	return this->ground;
}

	
std::map <int, Unit*> &Model::get_units(){
	return this->units;
}

void Model::deleteUnits(){
	for(auto iter = units.begin(); iter != units.end(); ++iter){
		delete &iter->second;
	}	
}


Model::~Model(){
	deleteUnits();
	//~this->ground;	
}



