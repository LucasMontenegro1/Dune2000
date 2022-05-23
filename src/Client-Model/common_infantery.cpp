#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_infantery.h"


Infantery::Infantery(int cordX, int cordY): Unit(cordX, cordY) {
	texture.loadFromFile("infantery.png");
	sprite.setTexture(texture);
}


//50 y 50 lo tendre dependera de el largo y el ancho de los bits en la imagen 
bool is_there(int cord_x, int cord_y){
	bool is_here = false;
	if(this->x <= cord_x && cord_x <= this->x + 50) is_here = true;
	if(this->y <= cord_y && cord_y<= this->y + 50) is_here = true;
	else is_here = false;
	return is_here;
}
