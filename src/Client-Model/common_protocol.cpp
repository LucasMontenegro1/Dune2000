#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include <iostream>
#include "common_trike.h"
#include "common_protocol.h"
#include "common_ground.h"
#include "../Server/mock_server.h"

Protocol::Protocol(): server{}, received(false) {}

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
	
	
std::vector<Unit*> Protocol::receive_units(){
	this->server.create_unit(0,0);
	std::vector<struct RawUnit> received_units = this->server.get_state();
	std::vector<Unit*> units;
	for(size_t i = 0; i < received_units.size(); i++){
		if(!this->received || !received_units[i].changed){
			Trike trike(received_units[i].col, received_units[i].row, received_units[i].id);
			units.push_back(&trike);
		}
	}
	if(!this->received) this->received = true;
	return units;
}
	
	
void Protocol::send_unit_move(int unit_id, float cordX, float cordY){
	this->server.move_unit(unit_id, (int) cordX / 16, (int) cordY / 16);
}

void Protocol::update(){
	this->server.update();
}
