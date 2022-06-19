#ifndef COMMON_CANYON_H
#define COMMON_CANYON_H
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>


using namespace sf;


class Canyon: public Drawable{
    Sprite sprite;
	Texture texture;
	Image image;
	SoundBuffer buffer;
	Sound attackSound;
	int cont;

	void updateTexture(int frame);

    public:
    void draw(RenderTarget &target, RenderStates states) const;

    Canyon();

	void animate(float posX, float posY, bool is_attacking, int frame);

    Sprite getSprite();

};
#endif