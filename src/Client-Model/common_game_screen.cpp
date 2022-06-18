#include <iostream>
#include <string>
#include <fstream>
#include <arpa/inet.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <cstring>
#include <tuple>
#include <map>
#include "client.h"
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_protocol.h"
//#include "common_socket.h"
#include "common_model.h"
#include "common_game_screen.h"
#include "common_unit.h"
#include "common_camera.h"
#include "common_ground.h"
#include "common_pointer.h"


using namespace sf;


GameScreen::GameScreen(): posX(0), posY(0) {}


void GameScreen::draw_elements(RenderWindow &window, Model &model, 
						Camera &camera, int sizeX, int sizeY){
	int posX = camera.get_posX();
	int posY = camera.get_posY();
	int limitX = posX +  sizeX;
	int limitY = posY + sizeY;
	Ground &ground = model.get_grounds();
	for(int i = posX; i < limitX; i+=16){
		for(int j = posY; j < limitY; j +=16){
			int col = i / 16;
			int row = j / 16;
			if(ground.identify_texture(col, row)){
				ground.set(i,j);
				window.draw(ground);
			}
		}
	}
	for(auto iter = model.get_units().begin(); iter != model.get_units().end(); ++iter){
		model.move_by_position(iter->first);
		std::tuple<int, int, int, int> uBits = iter->second->get_bits();
		if(camera.appears_in_view(std::get<0>(uBits), std::get<1>(uBits), 
								std::get<2>(uBits), std::get<3>(uBits))){
			window.draw(*iter->second);
			if(iter->second->is_attacking()){
				iter->second->animate_attack();
				window.draw(iter->second->get_weapon());
			}
		}
	}	
}



void GameScreen::check_events(Pointer &pointer, Event &event, Model &model, 
			Protocol &protocol, int posX, int posY){
	if(event.mouseButton.button == Mouse::Left){
		if(model.is_unit_there(event.mouseButton.x + posX, event.mouseButton.y + posY)){
			int unit = model.get_unit(event.mouseButton.x + posX, event.mouseButton.y + posY);
			model.unit_enable_move(unit); 
			pointer.unit_move_mode();
		} else {
			model.no_enable_moves();
			pointer.normal_mode();
		} 
	}
	if(event.mouseButton.button == Mouse::Right){
		if(model.a_unit_can_moves()){
			std::vector<int> units_to_move = model.get_units_can_moves();
			for(size_t i = 0; i < units_to_move.size(); i++){
				if(model.is_enemy_there(event.mouseButton.x + posX, event.mouseButton.y + posY)){
					int enemy_unit = model.get_unit(event.mouseButton.x + posX, event.mouseButton.y + posY);
					protocol.send_unit_attack(units_to_move[i], enemy_unit);
				} else {
					protocol.send_unit_move(units_to_move[i], event.mouseButton.x + posX, 
											event.mouseButton.y + posY);
				}
			}
		}
	}
}


void GameScreen::show(Model &model, Protocol &protocol){
	int sizeX = 500;//Esto en un futuro es 
	int sizeY = 500;//Algo que se pasa por parametro
	RenderWindow window(VideoMode(sizeX, sizeY), "DUNE");
	View view;
	Camera camera(view, this->posX, this->posY, sizeX, sizeY);

	Pointer pointer(window, model.get_team());
	
	while(window.isOpen()){
		Vector2i posicion = Mouse::getPosition(window);	
		camera.update(posicion, model);	
		protocol.receive_units(model.get_units());
		Event event;
		while(window.pollEvent(event)){
			if(event.type == Event::Closed){
				window.close();
			}
			check_events(pointer, event, model, protocol, this->posX, this->posY);
		}
		camera.render(window);
		window.clear();
		draw_elements(window, model, camera, sizeX, sizeY);
		pointer.update(posicion, posX, posY, window, model.get_units());
		window.display();
		protocol.update();
	}	
}
