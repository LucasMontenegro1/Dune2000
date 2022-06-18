#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include <iostream>
#include "common_trike.h"
#include "common_tank.h"
#include "common_protocol.h"
#include "common_ground.h"
#include "../Server/mock_server.h"

Protocol::Protocol(): server{}, skins{} {
	this->server.create_unit(1, 1, 0,0);
	this->server.create_unit(1, 2, 8,8);
}

Ground Protocol::receive_grounds(){
	Cliffs map_received = this->server.get_map();
	std::vector<std::vector<int> > map;
	for(unsigned int i = 0; i < 360; i++){
		std::vector<int> actual_row;
		for(unsigned int j = 0; j < 360; j++){
			if(map_received[j].first == i && map_received[j].second == j) actual_row.push_back(3);
			else actual_row.push_back(0);
		}
		map.push_back(actual_row);
	}
	Ground grounds(map, 360, 360);
	return grounds;
}

	
void Protocol::receive_units(std::map <int, Unit*> &units){
	std::vector<struct RawUnit> received_units = this->server.get_state();
	for(size_t i = 0; i < received_units.size(); i++){
		int id_received = received_units[i].id;
		if(units.count(id_received) != 0){
			std::tuple<float, float> actual_position = units[id_received]->get_position();
			if(received_units[i].col != ((unsigned int) std::get<0>(actual_position) / 16) && 
					received_units[i].row != ((unsigned int) std::get<1>(actual_position) / 16)){
				units[id_received]->setMove(received_units[i].col * 16, received_units[i].row * 16);
			}
		} else {
			if(received_units[i].type_id == 2){
				units.insert(std::pair<int, Unit*>(received_units[i].id, new Trike(skins.trike, (int) received_units[i].col * 16, 
												(int) received_units[i].row * 16, received_units[i].id, 0, received_units[i].hp)));	
			}
			if(received_units[i].type_id == 1){
				units.insert(std::pair<int, Unit*>(received_units[i].id, new Tank(skins.tank, (int) received_units[i].col * 16, 
												(int) received_units[i].row * 16, received_units[i].id, 1, received_units[i].hp)));		
			}
		}
	}
}

void Protocol::send_unit_attack(int unit_id, int unit_target_id){
	this->server.unit_attack(unit_id, unit_target_id);
}


	
void Protocol::send_unit_move(int unit_id, float cordX, float cordY){
	this->server.move_unit(unit_id, (int) cordY / 16, (int) cordX / 16);
}

void Protocol::update(){
	this->server.update(100);
}
