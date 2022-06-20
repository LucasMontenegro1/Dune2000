#ifndef COMMON_BUILD_H
#define COMMON_BUILD_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>

using namespace sf;


class BuildClient: public Drawable{
	public:
    bool is_selected;
	RectangleShape lifeMax;
	RectangleShape lifeRest;
	float posX;
	float posY;
	int largeBitsX;
	int largeBitsY;
	int cont;
	int frameBuild;
	int hp;
	int hpMax;
	int team;

	BuildClient(float x, float y, int team, int hp);

	void draw(RenderTarget &target, RenderStates states) const;
		
	void modifyHp(int new_hp);
	
	bool is_there(float cord_x, float cord_y);

    void selected_structure();

    void deselected_structure();
	
	int get_team();
	
	std::tuple<int, int, int, int> get_bits();
	
	virtual void animateBuild();

};



#endif