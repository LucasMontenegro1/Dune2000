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
	int actualFrame;
	Sprite sprite;
	Texture texture;
	Selector selector;
	int team;
	int cont;
	int hp;
	int max_hp;
	bool is_attacking;
	int attackX;
	int attackY;

	virtual void modifyMovePosition(bool moveRight, bool moveLeft, 
								bool moveUp, bool moveDown);
	
	Unit(int cordX, int cordY, int id, int team, int hp);
	
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

	int get_team();
	
	std::tuple<float, float> get_position();
	
	Unit& operator=(const Unit&& other);

};
#endif
