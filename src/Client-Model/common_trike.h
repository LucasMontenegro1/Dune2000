#ifndef COMMON_TRIKE_H
#define COMMON_TRIKE_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_assault.h"


using namespace sf;

class Trike: public Unit{
	std::map <int, Vector2f> &frames;
	Assault weapon;
	
	virtual void modifyMovePosition(bool moveRight, bool moveLeft, 
								bool moveUp, bool moveDown) override;
	
	void pointTo();

	public:
	
	Trike(std::map <int, Vector2f> &frames, int cordX, int cordY, int id, int team, int hp);

	virtual void animate_attack() override;

	virtual Assault get_weapon() override;

	virtual ~Trike();

	
};
#endif
