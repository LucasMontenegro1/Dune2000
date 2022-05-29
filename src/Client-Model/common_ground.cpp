#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <tuple>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_ground.h"

using namespace sf;

void Ground::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}

Ground::Ground(int cordX, int cordY, int type){
	this->largo = 16;
	this->x = cordX * largo;
	this->y = cordY * largo;
	texture.loadFromFile("terrain.bmp");
	sprite.setTexture(texture);
	if(type == 0) sprite.setTextureRect(IntRect(0,8,largo,largo)); //Por ahora solo arena
	sprite.setPosition(x, y);	
}

int Ground::get_x_max(){
	return this->x + this->largo;
}
	
int Ground::get_y_max(){
	return this->y + this->largo;
}

std::tuple<int> Ground::get_bits(){
	return std::make_tuple(this->x, this->y, this->largo);
}
