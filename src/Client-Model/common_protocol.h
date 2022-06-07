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
	bool received;

	public:
	Protocol(): received_units(false);
	
	std::vector<Ground*> receive_grounds(Socket &socket, bool &was_closed);
	
	
	std::vector<Unit*> receive_units(Socket &socket, bool &was_closed);
	
	
	void send_unit_move(Socket &socket, Unit &unit, float cordX, float cordY);
	
	void update();
};
#endif
