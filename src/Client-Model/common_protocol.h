#ifndef COMMON_PROTOCOL_H
#define COMMON_PROTOCOL_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <map>
#include "common_unit.h"
#include "common_trike.h"
#include "common_tank.h"
//#include "common_socket.h"
#include "common_ground.h"
#include "common_frames.cpp"
#include "../Server/mock_server.h"

class Protocol {
	MockServer server;
	Skins skins;

	public:
	Protocol();
	
	Ground receive_grounds();
	
	std::vector<struct RawUnit> receive_units(std::map <int, Unit*> &units);
	
	void send_unit_attack(int unit_id, int unit_target_id);
	
	void send_unit_move(int unit_id, float cordX, float cordY);
	
	void update();

    void createTrike();
};
#endif
