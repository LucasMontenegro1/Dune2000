#ifndef COMMON_TANK_H
#define COMMON_TANK_H
#include <vector>
#include <string>
#include <tuple>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "common_unit.h"
#include "common_canyon.h"
#include <SFML/Audio.hpp>


using namespace sf;

class TankClient: public Unit {
	int actualFrameCanion;
	Sprite canion;
	std::map <int, Vector2f> &frames;
    Canyon weapon;
	SoundBuffer buffer;
	Sound moveSound;

    void updateCanion();

	public:
	TankClient(std::map <int, Vector2f> &frames, int cordX, int cordY, int id, int team, int hp);
	
	void draw(RenderTarget &target, RenderStates states) const;

    virtual void modifyMovePosition(bool moveRight, bool moveLeft, 
							bool moveUp, bool moveDown) override;

    virtual void animate_attack() override;

	virtual Sprite get_weapon() override;

	virtual void reproduceMove() override;
	
    virtual ~TankClient();

};
#endif