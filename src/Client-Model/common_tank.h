#ifndef COMMON_TANK_H
#define COMMON_TANK_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"

using namespace sf;

class Tank: public Unit{
	int actualFrameCanion;
	Sprite canion;
	std::map <int, Vector2f> &frames;

    virtual void modifyMovePosition(bool moveRight, bool moveLeft, 
							bool moveUp, bool moveDown) override;

	public:
	Tank(std::map <int, Vector2f> &frames, int cordX, int cordY, int id, int team, int hp);
	
	void draw(RenderTarget &target, RenderStates states) const;
	
    //virtual ~Tank();

};
#endif