#ifndef COMMON_ASSAULT_H
#define COMMON_ASSAULT_H
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;


class Assault: public Drawable{
	Sprite sprite;
	Texture texture;
	Image image;
	int cont;

	void updateTexture();

    public:
    void draw(RenderTarget &target, RenderStates states) const;

    Assault();

	void animate(float posX, float posY, bool is_attacking);


};
#endif