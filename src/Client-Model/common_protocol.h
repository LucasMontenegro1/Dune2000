#ifndef COMMON_PROTOCOL_H
#define COMMON_PROTOCOL_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
//#include "common_socket.h"
#include "common_ground.h"
#include "../Server/mock_server.h"

class Protocol {
	MockServer server;

	public:
	Protocol();
	
	Ground receive_grounds();
	
	
	std::vector<Unit*> receive_units();
	
	
	void send_unit_move(int unit_id, float cordX, float cordY);
	
	void update();
};
#endif
