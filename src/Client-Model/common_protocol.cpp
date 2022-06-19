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
	this->server.create_unit(0, 2, 0, 0);
	this->server.create_unit(0, 1, 5, 5);
	this->server.create_unit(1, 1, 15,15);
	this->server.create_unit(1, 1, 0,30);

}

Ground Protocol::receive_grounds(){
	vector<pair<struct map_coor, unsigned int>> terrains;
	for (unsigned int i = 60; i <= 100; i++)
		terrains.push_back(pair<struct map_coor, unsigned >({i, 60}, 4));
	this->server.load_map(terrains);

	std::vector<std::vector<int> > map;
	for(size_t row = 0; row <= 360; row++){
		std::vector<int> actual_row;
		for(size_t col = 0; col <= 360; col++){
			actual_row.push_back(0);
		}
		map.push_back(actual_row);
	}
	for(size_t i = 0; i < terrains.size(); i++){
		map[terrains[i].first.row][terrains[i].first.col] = terrains[i].second;
	}

	Ground grounds(map, 360, 360);
	return grounds;
}


	
std::vector<struct RawUnit> Protocol::receive_units(std::map <int, Unit*> &units){
	std::vector<struct RawUnit> received_units = this->server.get_state();
	for(size_t i = 0; i < received_units.size(); i++){
		int id_received = received_units[i].id;
		if(units.count(id_received) != 0){
			if(received_units[i].state == "moving"){
				units[id_received]->setMove(received_units[i].col * 16, received_units[i].row * 16);
			}
			if(received_units[i].state == "attacking"){
 				if(units.count(received_units[i].target_id) == 0) continue;
				units[id_received]->setAttack(units[received_units[i].target_id]->get_position());
				units[received_units[i].target_id]->modifyHp(received_units[i].hp);
			} else if(received_units[i].state == "neutral"){
				units[id_received]->setNeutral();
			}
		} else {
			if(received_units[i].type_id == 1){
				units.insert(std::pair<int, Unit*>(received_units[i].id, new Trike(skins.trike, (int) received_units[i].col * 16, 
							(int) received_units[i].row * 16, received_units[i].id, received_units[i].player_id, received_units[i].hp)));	
			}
			if(received_units[i].type_id == 2){
				units.insert(std::pair<int, Unit*>(received_units[i].id, new TankClient(skins.tank, (int) received_units[i].col * 16, 
							(int) received_units[i].row * 16, received_units[i].id, received_units[i].player_id, received_units[i].hp)));		
			}
		}
	}
	return received_units;
}


void Protocol::send_unit_attack(int unit_id, int unit_target_id){
	this->server.unit_attack(unit_id, unit_target_id);
}


	
void Protocol::send_unit_move(int unit_id, float cordX, float cordY){
	this->server.move_unit(unit_id, (int) cordY / 16, (int) cordX / 16);
}

void Protocol::update(){
	this->server.update(10);
}
