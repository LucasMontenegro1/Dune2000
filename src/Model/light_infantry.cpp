//
// Created by ignat on 10/06/22.
//

#include "light_infantry.h"

const unsigned int START_HP = 50;
const unsigned int INFANTRY_ID = 1;
const unsigned int LIGHT_INFANTRY_ID = 1;

LightInfantry::LightInfantry(uint id_, uint player_id_, BlockPosition pos_, const TerrainMap &map_) :
	Movable(id_, player_id_, START_HP, pos_, map_){}

bool LightInfantry::can_traverse(BlockTerrain terrain) const
{
	return this->mob.can_traverse(terrain);
}

const UnitMobility &LightInfantry::get_mobility() const
{
	return this->mob;
}

unsigned int LightInfantry::get_class_id() const
{
	return INFANTRY_ID;
}

unsigned int LightInfantry::get_type_id() const
{
	return LIGHT_INFANTRY_ID;
}

LightInfantry::~LightInfantry() noexcept = default;
