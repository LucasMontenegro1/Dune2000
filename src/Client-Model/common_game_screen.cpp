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
#include "common_unit.h"
#include "common_ground.h"

using namespace sf;


GameScreen::GameScreen(): posX(0), posY(0) {}


void GameScreen::draw_elements(RenderWindow &window, Model &model){
	for(int i = 0; i < model.get_grounds_size() ; i++){
		window.draw((model.get_grounds())[i]);
	}
	for(int i = 0; i < model.get_units_size() ; i++){
		window.draw((model.get_units())[i]);
	}
}


void GameScreen::screen_move(RenderWindow &window, View &view, 
						int sizeX, int sizeY, Model &model){
						
	int large_x_map = model.get_x_size() * 10; //ese 10 lo voy a tener que cambiar por el tamaño
	int large_y_map = model.get_y_size() * 10; // en bits de cada cuadrado de terreno 

	Vector2i posicion = Mouse::getPosition(window);
	if(posicion.x + 10 >= sizeX) posX += 1;
	if(posicion.y + 10 >= sizeY) posY += 1;
	if(posicion.x - 10 <= 0) posX -= 1;
	if(posicion.y - 10 <= 0) posY -= 1;
	if(posX < 0) posX = 0;
	if(posY < 0) posY = 0;
	if(posX > large_x_map) posX = large_x_map;
	if(posY > large_y_map) posY = large_y_map;
	view.reset(FloatRect(posX, posY, sizeX, sizeY));	
}


void GameScreen::check_events(Event &event, Model &model, 
			ProtocolGame &protocol, Socket &conexion){
	if(event.mouseButton.button == Mouse::Left){
		if(model.is_unit_there(event.mouseButton.x + posX, event.mouseButton.y + posY){
			Unit unit = model.get_unit(event.mouseButton.x + posX, event.mouseButton.y + posY);
			model.unit_enable_move(unit.get_id_unit();); 
			//todas las otras units quedan inhabilitadas para moverse
		} else if(model.is_ground_there(event.mouseButton.x + posX, 
					event.mouseButton.y + posY && model.a_unit_can_moves()){
			Unit unit = model.get_unit_can_moves();
			protocol.send_unit_move(socket, unit, event.mouseButton.x + posX, 
													event.mouseButton.y + posY);
		} /*else if(model.is_unit_there(event.mouseButton.x + posX, 
					event.mouseButton.y + posY && model.a_unit_can_moves()){
			Unit unit = model.get_unit_can_moves();
			Unit enemy = model.get_unit(event.mouseButton.x + posX, event.mouseButton.y + posY);
			protocol.send_unit_atack(socket, unit, enemy);
		}*/
	}
}


void GameScreen::show(Model &model, ProtocolGame &protocol, Socket &conexion, bool was_closed){
	int sizeX = 500;//Esto en un futuro es 
	int sizeY = 500;//Algo que se pasa por parametro
	RenderWindow window(VideoMode(sizeX, sizeY), "DUNE");
	
	View view;
	view.reset(FloatRect(posX, posY, sizeX, sizeY));
	view.setViewport(FloatRect(posX, posY, 1.0f, 1.0f));
	
	while(window.isOpen()){
		screen_move(window, view, sizeX, sizeY, model);
		model.update_status(protocol.receive_status(conexion, &was_closed));
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed){
				window.close()
			}
			check_events(event, model);
		}
	
	}	
	window.setView(view);
	draw_elements(window, model);
	window.clear();
	window.display();
}
