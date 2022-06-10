//
// Created by ignat on 10/06/22.
//

#include "assault_rifle.h"

const unsigned int DAMAGE = 2;
const unsigned int RECHARGE_TIME = 167; // 1/6 segundo

AssaultRifle::AssaultRifle() :
	Weapon(DAMAGE, RECHARGE_TIME){}

unsigned int AssaultRifle::bonus_damage(unsigned int target_class_id) const
{
	if (target_class_id == 1)
		return 1;
	else
		return 0;
}

unsigned int AssaultRifle::get_weapon_id() const
{
	return 1;
}

AssaultRifle::~AssaultRifle() = default;
