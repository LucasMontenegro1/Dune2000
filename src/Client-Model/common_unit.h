#ifndef COMMON_UNIT_H
#define COMMON_UNIT_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_selector.h"

using namespace sf;

class Unit: public Drawable{
	public: 
	float posX;
	float posY;
	bool can_move;
	float destX;
	float destY;
	int id;
	float velocity;
	int largeBitsX;
	int largeBitsY;
	std::map <int, Vector2f> frames;
	int actualFrame;
	Sprite sprite;
	Texture texture;
	Selector selector;
	int cont;

	virtual void modifyMovePosition(bool moveRight, bool moveLeft, 
								bool moveUp, bool moveDown) = 0;
	
	Unit(int cordX, int cordY, int id);
	
	void draw(RenderTarget &target, RenderStates states) const;
	
	void move();
	
	std::tuple<int, int, int, int> get_bits();

	bool is_there(float cord_x, float cord_y);
	
	void enable_move();
	
	void no_enable_move();
	
	bool can_moves();
	
	void setMove(float x, float y);
	
	bool is_in_destiny();
	
	int get_id_unit();
	
	std::tuple<float, float> get_position();
	
	Unit& operator=(const Unit&& other);

	virtual ~Unit();
};
#endif
