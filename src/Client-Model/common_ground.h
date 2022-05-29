#ifndef COMMON_GROUND_H
#define COMMON_GROUND_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class Ground: public Drawable{
	Sprite sprite;
	Texture texture;
	
	int x;
	int y;
	int largo;
	
	public:
	Ground(int cordX, int cordY, int type);
	
	int get_x_max();
	
	int get_y_max();
	
	std::tuple<int> get_bits();
	
	void draw(RenderTarget &target, RenderStates states) const;
};
#endif
