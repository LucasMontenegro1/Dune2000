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
#include "common_pointer.h"

using namespace sf;

Pointer::Pointer(RenderWindow &window){
	this->frame = 1;
	this->cont = 0;
	window.setMouseCursorVisible(false);
	texture.loadFromFile("cursores.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0,15,30,27)); 
	fillFrames();
}
	
void Pointer::updateTexture(){
	Vector2f &posicionFrame = frames[frame];
	sprite.setTextureRect(IntRect(posicionFrame.x, posicionFrame.y,30,27));
	frame++;
	if(frame == 8) frame = 1;
}

void Pointer::update(Vector2i &posicion, int posX, int posY, RenderWindow &window){
	sprite.setPosition(posicion.x + posX - 15, posicion.y + posY - 15);
	if(cont % 30 == 0) updateTexture();
	window.draw(sprite);
	cont++;
}
	
void Pointer::fillFrames(){
	frames.insert(std::pair<int,Vector2f>(1, Vector2f(0,15)));
	frames.insert(std::pair<int,Vector2f>(2, Vector2f(35,15)));
	frames.insert(std::pair<int,Vector2f>(3, Vector2f(70,15)));
	frames.insert(std::pair<int,Vector2f>(4, Vector2f(100,15)));
	frames.insert(std::pair<int,Vector2f>(5, Vector2f(135,15)));
	frames.insert(std::pair<int,Vector2f>(6, Vector2f(168,15)));
	frames.insert(std::pair<int,Vector2f>(7, Vector2f(200,15)));
	frames.insert(std::pair<int,Vector2f>(8, Vector2f(233,15)));	
}