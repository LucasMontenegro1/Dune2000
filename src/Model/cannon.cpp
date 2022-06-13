//
// Created by ignat on 13/06/22.
//

#include "cannon.h"

Cannon::Cannon() :
	Weapon(7, 1000){}

unsigned int Cannon::bonus_damage(unsigned int target_class_id) const
{
	return 0;
}

unsigned int Cannon::get_weapon_id() const
{
	return 2;
}

Cannon::~Cannon() = default;