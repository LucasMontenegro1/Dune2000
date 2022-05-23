#ifndef COMMON_UNIT_H
#define COMMON_UNIT_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class Unit: public Drawable{
	Sprite sprite;
	Texture texture;
	bool can_move;
	int posX;
	int posY;
	
	public:
	Unit unit();
	
	Unit unit(int cordX, int cordY);
	
	void draw(RenderTarget &target, RenderStates states) const;

	bool is_there(int cord_x, int cord_y) override;
	
	void enable_move();
	
	void no_enable_move();
	
	bool can_moves();
	
	Unit& operator=(const Unit&& other);
}
#endif
