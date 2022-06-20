#include <iostream>
#include <string>
#include <fstream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <cstring>
#include <tuple>
#include "client.h"
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_protocol.h"
//#include "common_socket.h"
#include "common_model.h"
#include "common_game_screen.h"
#include <map>


using namespace sf;

Client::Client(): protocol{}, screen{} {}
	
	
void Client::show_window(){
	int team = 0; //Protocol.receive_player_code();
	Ground ground = protocol.receive_grounds();
	std::map <int, Unit*> units;
	std::map <int, BuildClient*> builds;
	protocol.receive_units(units);
	protocol.receive_builds(builds);
	Model model(units, builds, ground, team);
	this->screen.show(model, this->protocol);
	//this->conexion.shutdown(0);
}


