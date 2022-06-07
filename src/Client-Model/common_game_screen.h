#ifndef COMMON_GAME_SCREEN_H
#define COMMON_GAME_SCREEN_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_protocol.h"
//#include "common_socket.h"
#include "common_model.h"
#include "common_camera.h"

class GameScreen {
	int posX;//Posiciones de la camara respecto al mapa
	int posY;
	
	void check_events(Event &event, Model &model, 
			ProtocolGame &protocol, int posX, int posY);
	
	void draw_elements(RenderWindow &window, Model &model, Camera &camera);
	
	public:
	GameScreen();
	
	void show(Model &model, Protocol &protocol);

};
#endif
