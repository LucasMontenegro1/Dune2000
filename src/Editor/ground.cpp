#include <vector>
#include <SFML/Graphics.hpp>
#include "ground.h"

using namespace sf;

void Ground::draw(RenderTarget &target, RenderStates states) const {
	target.draw(sprite, states);
}

Ground::Ground(std::vector<std::vector<int> >& level, int lenght, int width): map(level),
					lengthMap(lenght), widthMap(width) {
	texture.loadFromFile("../resources/terrain.bmp");
	sprite.setTexture(texture);
}

void Ground::is_sand(){
	sprite.setTextureRect(IntRect(0,8,16,16));
}
	
void Ground::is_rock(){
	sprite.setTextureRect(IntRect(112,240,16,16));
}
	
void Ground::is_spice(){
	sprite.setTextureRect(IntRect(0,305,16,16));
}

void Ground::set(int x, int y){
	sprite.setPosition((float) x,(float)y);
}

bool Ground::identify_texture(int col, int row){
	bool identify = false;
	if(col >= lengthMap || row >= widthMap) return false;
	switch(map[row][col]){
		case 0:
			is_sand(); identify = true;
			break;
		case 1:
			is_rock(); identify = true;
			break;
		case 2:
			is_spice(); identify = true;
			break;
	}
	return identify;
}


//
int Ground::get_ground_y_size() const{
	return lengthMap * 16;
}
	
int Ground::get_ground_x_size() const{
	return widthMap * 16;
}

void Ground::setsSprite(int x, int y, int code) {
    map[x][y] = code;

}

