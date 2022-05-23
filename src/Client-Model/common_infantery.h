#ifndef COMMON_INFANTERY_H
#define COMMON_INFANTERY_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"

using namespace sf;

class Infantery: public Unit{
	
	public:
	
	Infantery(int cordX, int cordY);

	bool is_there(int cord_x, int cord_y);
	
}
#endif
