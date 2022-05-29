#ifndef COMMON_PROTOCOL_H
#define COMMON_PROTOCOL_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_units.h"
#include "common_socket.h"
#include "common_grounds.h"

class Protocol {

	public:
	std::vector<Ground*> receive_grounds(Socket &socket, bool &was_closed);
	
	
	std::vector<Unit*> receive_units(Socket &socket, bool &was_closed);
	
	
	void send_unit_move(Socket &socket, Unit &unit, float cordX, float cordY);
	
}
#endif
