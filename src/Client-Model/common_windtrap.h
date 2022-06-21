#ifndef COMMON_WINDTRAP_H
#define COMMON_WINDTRAP_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_build.h"
#include <SFML/Audio.hpp>

using namespace sf;


class WindTrap: public BuildClient{
	std::map <int, Vector2f> &frames;
    int frameWindow;
	bool is_constructed;
	Texture textBuild;
	Sprite spriteBuild;
	Sprite windows;
	Texture textConstruction;
	Sprite spriteConstruction;
	int frameConstruction;

	void construct();

	public:
	
	WindTrap(std::map <int, Vector2f> &frames, float x, float y, int team, int id, int hp);
	
	void draw(RenderTarget &target, RenderStates states) const;
		
	virtual void animateBuild() override;
	
    virtual ~WindTrap();


};


#endif