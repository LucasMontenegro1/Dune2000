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
#include "common_socket.h"
#include "common_model.h"
#include "common_game_screen.h"

using namespace sf;

Client::Client(const char* hostname, const char* service): protocol{}, 
					conexion{hostname, service}, was_closed(false), screen{} {}
	
	
void Client::show_window(){
	Model model(protocol.receive_status(conexion, &was_closed);
	this->screen.show(model, this->protocol, this->conexion, &was_closed);
	this->conexion.shutdown(0);
}


