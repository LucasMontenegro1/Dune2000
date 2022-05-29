#ifndef COMMON_INFANTERY_H
#define COMMON_INFANTERY_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"

using namespace sf;

class Trike: public Unit{
	
	void modifyMovePosition(bool moveRight, bool moveLeft, 
								bool moveUp, bool moveDown);
	
	public:
	
	Trike(int cordX, int cordY);

	virtual void move() override;
	
}
#endif
