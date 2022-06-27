#ifndef CLIENT_CLASS_H
#define CLIENT_CLASS_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_protocol.h"
//#include "common_socket.h"
#include "common_model.h"
#include "common_game_screen.h"

class Client {
    Protocol protocol;
    GameScreen screen;
    
	public:
	Client();
	void show_window();
};
#endif
