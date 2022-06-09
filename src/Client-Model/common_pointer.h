#ifndef COMMON_POINTER_H
#define COMMON_POINTER_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class Pointer {
	Texture texture;
	Sprite sprite;
	int frame;
	int cont;
	std::map <int, Vector2f> frames;
	
	void fillFrames();

	public:
	Pointer(RenderWindow &window);
	
	void updateTexture();

	void update(Vector2i &posicion, int posX, int posY, RenderWindow &window);

};
#endif
