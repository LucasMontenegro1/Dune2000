#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_ground.h"
#include "common_model.h"

Model::Model(std::vector<Unit*> &units, std::vector<Ground*> &grounds): 
		units(units), grounds(grounds), one_unit_can_moves(false) {}
		
		
void Model::update_status(std::vector<Unit*> &units, std::vector<Ground*> &grounds){
	this->units.deleteUnits();
	this->units = std::move(units);
	this->grounds.deleteGrounds();
	this->grounds = std::move(grounds);
}


Unit Model::get_unit(int cordX, int cordY){
	Unit unit;
	for(int i = 0; i < this->units.size() ; i++){
		if(is_unit_there(int cordX, int cordY){
			unit = this->units[i];
		}
	}
	return unit;
}


Unit Model::get_unit_can_moves(){
	Unit unit;
	for(int i = 0; i < this->units.size() ; i++){
		if(this->units[i].can_moves()){
			unit = this->units[i];
		}
	}
	return unit;	
}


bool Model::a_unit_can_moves(){
	return this->one_unit_can_moves;
}


void Model::unit_enable_move(int unit_id){
	for(int i = 0; i < this->units.size() ; i++){
		this->units[i].no_enable_move();
		if(this->units[i].get_id_unit() == unit_id){
			this->units[i].enable_move();
		}
	}	
}


bool Model::is_unit_there(int cordX, int cordY){
	bool is_here = false;
	for(int i = 0; i < this->units.size() ; i++){
		if(this->units[i].is_there(int cordX, int cordY)) is_here = true;
	}	
	return is_here;
}


bool Model::is_ground_there(int cordX, int cordY){
	bool is_here = true;
	for(int i = 0; i < this->units.size() ; i++){
		if(this->units[i].is_there(int cordX, int cordY)) is_here = false;
	}		
	for(int i = 0; i < this->grounds.size() ; i++){
		if(!this->grounds[i].is_there(int cordX, int cordY)) is_here = false;
	}		
	return is_here;
}


int Model::get:grounds_size(){
	return this->grounds.size();
}


int Model::get:units_size(){
	return this->units.size();
}


std::vector<Ground*> Model::get_grounds(){
	return this->grounds;
}

	
std::vector<Units*> Model::get_units(){
	return this->units;
}

void Model::deleteUnits(){
	for(int i = 0; i < this->units.size() ; i++){
		delete(this->units[i]);
	}		
}

void Model::deleteGrounds(){
	for(int i = 0; i < this->grounds.size() ; i++){
		delete(this->grounds[i]);
	}		
}





