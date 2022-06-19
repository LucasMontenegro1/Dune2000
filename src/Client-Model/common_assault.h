#ifndef COMMON_ASSAULT_H
#define COMMON_ASSAULT_H
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>


using namespace sf;


class Assault: public Drawable{
	Sprite sprite;
	Texture texture;
	Image image;
	SoundBuffer buffer;
	Sound attackSound;
	int cont;

	void updateTexture(int frame);

    public:
    void draw(RenderTarget &target, RenderStates states) const;

    Assault();

	void animate(float posX, float posY, bool is_attacking, int frame);

    Sprite getSprite();


};
#endif