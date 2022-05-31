//
// Created by ignat on 30/05/22.
//

#include "model_unit.h"

ModelUnit::ModelUnit(BlockPosition starting_pos, int id_) :
pos(starting_pos),
id(id_){}

bool ModelUnit::can_traverse(BlockTerrain terrain) const
{
	return this->mobility.can_traverse(terrain);
}

void ModelUnit::move_to(BlockPosition next_pos)
{
	this->pos = next_pos;
}

BlockPosition ModelUnit::get_pos() const
{
	return this->pos;
}

const UnitMobility &ModelUnit::get_mobility() const
{
	return this->mobility;
}

int ModelUnit::get_id() const
{
	return this->id;
}

ModelUnit::~ModelUnit() = default;

ModelUnit::ModelUnit(const ModelUnit &other) :
pos(other.pos),
id(other.id){}

ModelUnit &ModelUnit::operator=(const ModelUnit &other)
{
	if (this == &other)
		return *this;

	this->pos = other.pos;
	this->id = other.id;

	return *this;
}