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
	float posX;
	float posY;
	float destX;
	float destY;
	float velocity;
	int largeBitsX;
	int largeBitsY;
	int id;
	
	public:
	std::map <int, Vector2f> frames;
	int actualFrame;
	
	virtual void modifyMovePosition(bool moveRight, bool moveLeft, 
								bool moveUp, bool moveDown);
	
	Unit unit(int cordX, int cordY, int id);
	
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
};
#endif
