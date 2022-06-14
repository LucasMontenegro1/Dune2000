//
// Created by ignat on 10/06/22.
//

#include "light_infantry.h"

const unsigned int LIGHT_INF_HP = 50;
const unsigned int LIGHT_INF_CREATION_TIME = 60000;

LightInfantry::LightInfantry(unsigned int id, unsigned int player_id, BlockPosition position,
			     const TerrainMap &map_, std::map<unsigned int, TeamablePtr> &game_objects,
			     float creation_mod) :
	Unit(id, player_id, LIGHT_INF_HP, position, map_, game_objects,
	     LIGHT_INF_CREATION_TIME / creation_mod){}

unsigned int LightInfantry::get_class_id() const
{
	return 1;
}

unsigned int LightInfantry::get_type_id() const
{
	return 1;
}

unsigned int LightInfantry::get_weapon_id() const
{
	return this->rifle.get_weapon_id();
}

unsigned int LightInfantry::get_range() const
{
	return 3;
}

LightInfantry::~LightInfantry() = default;

const UnitMobility &LightInfantry::get_mobility() const
{
	return this->mob;
}

bool LightInfantry::can_traverse(BlockTerrain terrain) const
{
	return this->mob.can_traverse(terrain);
}

unsigned int LightInfantry::traverse_time(BlockTerrain terrain) const
{
	if (terrain == dunes)
		return 900;
	else
		return 450;
}

Weapon &LightInfantry::get_weapon()
{
	return this->rifle;
}