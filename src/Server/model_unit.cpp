//
// Created by ignat on 30/05/22.
//

#include "model_unit.h"

ModelUnit::ModelUnit(BlockPosition starting_pos, int id_) :
pos(starting_pos),
state(neutral),
id(id_){}

void ModelUnit::move_to(BlockPosition next_pos)
{
	this->pos = next_pos;
}

void ModelUnit::change_state(UnitState new_state)
{
	this->state = new_state;
}

BlockPosition ModelUnit::get_pos() const
{
	return this->pos;
}

UnitState ModelUnit::get_state() const
{
	return this->state;
}

int ModelUnit::get_id() const
{
	return this->id;
}

ModelUnit::~ModelUnit() = default;

ModelUnit::ModelUnit(const ModelUnit &other) :
pos(other.pos),
state(other.state),
id(other.id){}

ModelUnit &ModelUnit::operator=(const ModelUnit &other)
{
	if (this == &other)
		return *this;

	this->pos = other.pos;
	this->state = other.state;
	this->id = other.id;

	return *this;
}