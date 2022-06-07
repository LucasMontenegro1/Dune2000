#ifndef COMMON_CAMERA_H
#define COMMON_CAMERA_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_model.h"

using namespace sf;

class Camera {
	public:
	int &posX;
	int &posY;
	int sizeX;
	int sizeY;
	View &view;
	
	Camera(View &view, int &posX, int &posY, int sizeX, int sizeY);
	
	void render(RenderWindow &window);
	
	void update(Vector2i &posicion, Model &model);
	
	bool appears_in_view(int objectX, int objectY, int largeX, int largeY);
	
	int get_posX();
	
	int get_posY();
};
#endif
