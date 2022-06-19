#ifndef COMMON_CANYON_H
#define COMMON_CANYON_H
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf;


class Canyon: public Drawable{
    Sprite sprite;
	Texture texture;
	Image image;
	int cont;

	void updateTexture();

    public:
    void draw(RenderTarget &target, RenderStates states) const;

    Canyon();

	void animate(float posX, float posY, bool is_attacking);

    Sprite getSprite();

};
#endif