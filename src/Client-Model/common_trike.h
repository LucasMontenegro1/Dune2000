#ifndef COMMON_TRIKE_H
#define COMMON_TRIKE_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_assault.h"


using namespace sf;

class TrikeClient: public Unit {
	std::map <int, Vector2f> &frames;
	Assault weapon;
	SoundBuffer buffer;
	Sound moveSound;
	
	void pointTo();

	public:
	
	TrikeClient(std::map <int, Vector2f> &frames, int cordX, int cordY, int id, int team, int hp);

	virtual void modifyMovePosition(bool moveRight, bool moveLeft, 
								bool moveUp, bool moveDown) override;

	virtual void animate_attack() override;

	virtual Sprite get_weapon() override;

	virtual void reproduceMove() override;

	virtual ~TrikeClient();

	
};
#endif
