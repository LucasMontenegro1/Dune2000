#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"


std::vector<Ground*> Protocol::receive_grounds(Socket &socket, bool &was_closed){
	std::vector<Ground*> grounds;
	for(terrenos){
		cordX, cordY = terreno
		Ground ground = new Ground(cordX, cordY, 0);
		grounds.push_back(&ground);
	}
	return grounds;
}
	
	
std::vector<Unit*> Protocol::receive_units(Socket &socket, bool &was_closed){
	std::vector<Unit*> units;
	for(unidades){
		cordX, cordY = unidades
		Unit unit = new Unit(cordX * 16, cordY * 16);
		units.push_back(&unit);
	}
	return units;
}
	
	
void Protocol::send_unit_move(Socket &socket, Unit &unit, float cordX, float cordY){
	nueva cordX = cordX / 16;
	nueva cordY = cordY / 16;

}
